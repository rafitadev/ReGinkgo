#!/bin/bash
# ReGinkgo Build Script - Oficial

# Caminhos do Compilador
export PATH="$(pwd)/clang/bin:$PATH"
export ARCH=arm64
export SUBARCH=arm64

# Identidade do Kernel
export KBUILD_BUILD_USER="rafitadev"
export KBUILD_BUILD_HOST="ReGinkgo-Lab"
export KBUILD_COMPILER_STRING="Proton Clang"

echo "------- Configurando o Ginkgo -------"
mkdir -p out
make O=out ARCH=arm64 ginkgo_defconfig

# Força o nome ReGinkgo na versão do kernel
scripts/config --file out/.config --set-str CONFIG_LOCALVERSION "-ReGinkgo-v1.0"

echo "------- Iniciando Compilação -------"
make -j$(nproc --all) O=out \
    ARCH=arm64 \
    CC=clang \
    CLANG_TRIPLE=aarch64-linux-gnu- \
    CROSS_COMPILE=aarch64-linux-gnu- \
    CROSS_COMPILE_ARM32=arm-linux-gnueabi- \
    AR=llvm-ar \
    NM=llvm-nm \
    OBJCOPY=llvm-objcopy \
    OBJDUMP=llvm-objdump \
    STRIP=llvm-strip \
    LD=ld.lld

echo "------- ReGinkgo Pronto! -------"
