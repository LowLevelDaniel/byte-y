cmake_minimum_required(VERSION 3.22.1)
project(bytey)


include_directories(./)

add_executable(by
# local
  local/arena.c
  local/io.c
  local/program.c
# lexer
  psrc/parsing.c
  psrc/control_flow.c
  psrc/global.c
# writer
  wsrc/writer.c
)

