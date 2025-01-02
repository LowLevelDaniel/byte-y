#include <stdio.h>
#include <string.h>

// General-purpose CPUID wrapper
void get_cpuid(
  unsigned int eax_in, unsigned int ecx_in,
  unsigned int *eax_out, unsigned int *ebx_out,
  unsigned int *ecx_out, unsigned int *edx_out
) {
  asm volatile(
      "cpuid"
      : "=a" (*eax_out), "=b" (*ebx_out), "=c" (*ecx_out), "=d" (*edx_out)
      : "a" (eax_in), "c" (ecx_in)
  );
}

// Get vendor ID (EAX = 0)
void get_vendor_id(char *vendor) {
  unsigned int eax, ebx, ecx, edx;

  get_cpuid(0, 0, &eax, &ebx, &ecx, &edx);
  memcpy(vendor, &ebx, 4);
  memcpy(vendor + 4, &edx, 4);
  memcpy(vendor + 8, &ecx, 4);
  vendor[12] = '\0';
}

// Get processor brand string (EAX = 0x80000002 to 0x80000004)
void get_processor_brand(char *brand) {
  unsigned int eax, ebx, ecx, edx;

  for (int i = 0; i < 3; ++i) {
    get_cpuid(0x80000002 + i, 0, &eax, &ebx, &ecx, &edx);
    memcpy(brand + i * 16, &eax, 4);
    memcpy(brand + i * 16 + 4, &ebx, 4);
    memcpy(brand + i * 16 + 8, &ecx, 4);
    memcpy(brand + i * 16 + 12, &edx, 4);
  }
  brand[48] = '\0';
}

// Get processor info and features (EAX = 1)
void get_processor_info() {
  unsigned int eax, ebx, ecx, edx;

  get_cpuid(1, 0, &eax, &ebx, &ecx, &edx);

  unsigned int stepping = eax & 0xF;
  unsigned int model = (eax >> 4) & 0xF;
  unsigned int family = (eax >> 8) & 0xF;
  unsigned int type = (eax >> 12) & 0x3;

  printf("Processor Info:\n");
  printf("  Family: %u\n", family);
  printf("  Model: %u\n", model);
  printf("  Stepping: %u\n", stepping);
  printf("  Type: %u\n", type);
}

// Get cache and TLB info (EAX = 2)
void get_cache_info() {
  unsigned int eax, ebx, ecx, edx;

  get_cpuid(2, 0, &eax, &ebx, &ecx, &edx);

  printf("Cache and TLB Info (EAX=2):\n");
  printf("  EAX: 0x%x\n", eax);
  printf("  EBX: 0x%x\n", ebx);
  printf("  ECX: 0x%x\n", ecx);
  printf("  EDX: 0x%x\n", edx);
}

// Check feature flags (EAX = 1)
// Check feature flags (EAX = 7, ECX = 0)
// Check feature flags (EAX = 7, ECX = 1)
// Check feature flags (EAX = 7, ECX = 2)
void check_feature_flags() {
  unsigned int eax, ebx, ecx, edx;
  printf("Supported Features:\n");

  // Standard feature flags (EAX = 1)
  get_cpuid(1, 0, &eax, &ebx, &ecx, &edx);

  //ecx
  printf("  SSE3: %s\n", (ecx & (1 << 0)) ? "Yes" : "No");
  printf("  PCLMULQDQ: %s\n", (ecx & (1 << 1)) ? "Yes" : "No");
  printf("  DTES64: %s\n", (ecx & (1 << 2)) ? "Yes" : "No");
  printf("  MONITOR: %s\n", (ecx & (1 << 3)) ? "Yes" : "No");
  printf("  DS-CPL: %s\n", (ecx & (1 << 4)) ? "Yes" : "No");
  printf("  VMX: %s\n", (ecx & (1 << 5)) ? "Yes" : "No");
  printf("  SMX: %s\n", (ecx & (1 << 6)) ? "Yes" : "No");
  printf("  EST: %s\n", (ecx & (1 << 7)) ? "Yes" : "No");
  printf("  TM2: %s\n", (ecx & (1 << 8)) ? "Yes" : "No");
  printf("  SSSE3: %s\n", (ecx & (1 << 9)) ? "Yes" : "No");
  printf("  CNXT-ID: %s\n", (ecx & (1 << 10)) ? "Yes" : "No");
  printf("  SDBG: %s\n", (ecx & (1 << 11)) ? "Yes" : "No");
  printf("  FMA: %s\n", (ecx & (1 << 12)) ? "Yes" : "No");
  printf("  CX16: %s\n", (ecx & (1 << 13)) ? "Yes" : "No");
  printf("  XTPR: %s\n", (ecx & (1 << 14)) ? "Yes" : "No");
  printf("  PDCM: %s\n", (ecx & (1 << 15)) ? "Yes" : "No");
  printf("  PCID: %s\n", (ecx & (1 << 17)) ? "Yes" : "No");
  printf("  DCA: %s\n", (ecx & (1 << 18)) ? "Yes" : "No");
  printf("  SSE4.1: %s\n", (ecx & (1 << 19)) ? "Yes" : "No");
  printf("  SSE4.2: %s\n", (ecx & (1 << 20)) ? "Yes" : "No");
  printf("  X2APIC: %s\n", (ecx & (1 << 21)) ? "Yes" : "No");
  printf("  MOVBE: %s\n", (ecx & (1 << 22)) ? "Yes" : "No");
  printf("  POPCNT: %s\n", (ecx & (1 << 23)) ? "Yes" : "No");
  printf("  TSC-DEADLINE: %s\n", (ecx & (1 << 24)) ? "Yes" : "No");
  printf("  AES-NI: %s\n", (ecx & (1 << 25)) ? "Yes" : "No");
  printf("  XSAVE: %s\n", (ecx & (1 << 26)) ? "Yes" : "No");
  printf("  OSXSAVE: %s\n", (ecx & (1 << 27)) ? "Yes" : "No");
  printf("  AVX: %s\n", (ecx & (1 << 28)) ? "Yes" : "No");
  printf("  F16C: %s\n", (ecx & (1 << 29)) ? "Yes" : "No");
  printf("  RDRND: %s\n", (ecx & (1 << 30)) ? "Yes" : "No");
  printf("  HYPERVISOR: %s\n", (ecx & (1 << 31)) ? "Yes" : "No");
  
  //edx
  printf("  FPU: %s\n", (edx & (1 << 0)) ? "Yes" : "No");
  printf("  VME: %s\n", (edx & (1 << 1)) ? "Yes" : "No");
  printf("  DE: %s\n", (edx & (1 << 2)) ? "Yes" : "No");
  printf("  PSE: %s\n", (edx & (1 << 3)) ? "Yes" : "No");
  printf("  TSC: %s\n", (edx & (1 << 4)) ? "Yes" : "No");
  printf("  MSR: %s\n", (edx & (1 << 5)) ? "Yes" : "No");
  printf("  PAE: %s\n", (edx & (1 << 6)) ? "Yes" : "No");
  printf("  MCE: %s\n", (edx & (1 << 7)) ? "Yes" : "No");
  printf("  CX8: %s\n", (edx & (1 << 8)) ? "Yes" : "No");
  printf("  APIC: %s\n", (edx & (1 << 9)) ? "Yes" : "No");
  printf("  SEP: %s\n", (edx & (1 << 11)) ? "Yes" : "No");
  printf("  MTRR: %s\n", (edx & (1 << 12)) ? "Yes" : "No");
  printf("  PGE: %s\n", (edx & (1 << 13)) ? "Yes" : "No");
  printf("  MCA: %s\n", (edx & (1 << 14)) ? "Yes" : "No");
  printf("  CMOV: %s\n", (edx & (1 << 15)) ? "Yes" : "No");
  printf("  PAT: %s\n", (edx & (1 << 16)) ? "Yes" : "No");
  printf("  PSE-36: %s\n", (edx & (1 << 17)) ? "Yes" : "No");
  printf("  PSN: %s\n", (edx & (1 << 18)) ? "Yes" : "No");
  printf("  CLFSH: %s\n", (edx & (1 << 19)) ? "Yes" : "No");
  printf("  (NX): %s\n", (edx & (1 << 20)) ? "Yes" : "No");
  printf("  DS: %s\n", (edx & (1 << 21)) ? "Yes" : "No");
  printf("  ACPI: %s\n", (edx & (1 << 22)) ? "Yes" : "No");
  printf("  MMX: %s\n", (edx & (1 << 23)) ? "Yes" : "No");
  printf("  FXSR: %s\n", (edx & (1 << 24)) ? "Yes" : "No");
  printf("  SSE: %s\n", (edx & (1 << 25)) ? "Yes" : "No");
  printf("  SSE2: %s\n", (edx & (1 << 26)) ? "Yes" : "No");
  printf("  SS: %s\n", (edx & (1 << 27)) ? "Yes" : "No");
  printf("  HTT: %s\n", (edx & (1 << 28)) ? "Yes" : "No");
  printf("  TM: %s\n", (edx & (1 << 29)) ? "Yes" : "No");
  printf("  IA64: %s\n", (edx & (1 << 30)) ? "Yes" : "No");
  printf("  PBE: %s\n", (edx & (1 << 31)) ? "Yes" : "No");

  // Extended feature flags (EAX = 7, ECX = 0)
  get_cpuid(7, 0, &eax, &ebx, &ecx, &edx);

  // ebx

  // ecx

  // edx

  get_cpuid(7, 1, &eax, &ebx, &ecx, &edx);

  get_cpuid(7, 2, &eax, &ebx, &ecx, &edx);
}

// Get deterministic cache parameters (EAX = 4)
void get_cache_parameters() {
  unsigned int eax, ebx, ecx, edx;

  printf("Cache Parameters (EAX=4):\n");
  for (int i = 0; i < 4; ++i) { // Iterate over cache levels
    get_cpuid(4, i, &eax, &ebx, &ecx, &edx);
    if ((eax & 0x1F) == 0) break; // No more caches

    printf("  Cache Level: %u\n", (eax >> 5) & 0x7);
    printf("  Type: %u (1=Data, 2=Instruction, 3=Unified)\n", eax & 0x1F);
    printf("  Cache Size: %u KB\n", ((ecx >> 16) & 0xFFFF) * ((ebx & 0xFFF) + 1) * (((ebx >> 12) & 0x3FF) + 1));
  }
}

int main() {
  char vendor[13];
  char brand[49];

  // Get vendor ID
  get_vendor_id(vendor);
  printf("Vendor ID: %s\n", vendor);

  // Get processor brand string
  get_processor_brand(brand);
  printf("Processor Brand: %s\n", brand);

  // Get processor information
  get_processor_info();

  // Get cache and TLB information
  get_cache_info();

  // Check feature flags
  check_feature_flags();

  // Get cache parameters
  get_cache_parameters();

  return 0;
}
