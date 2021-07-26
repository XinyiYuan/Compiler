riscv64-unknown-elf-gcc out/asm.s -o out/test -L./libcact -lcact
spike pk out/test
