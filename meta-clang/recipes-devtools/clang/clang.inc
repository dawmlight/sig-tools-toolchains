LLVM_RELEASE = ""
LLVM_DIR = "llvm${LLVM_RELEASE}"

#LLVM_GIT ?= "git://github.com/llvm"
LLVM_GIT = "git://git.ostc-eu.org/OSTC/OHOS"
LLVM_GIT_PROTOCOL ?= "https"

MAJOR_VER = "12"
MINOR_VER = "0"
PATCH_VER = "0"

SRCREV ?= "6f7967533158691eed417291e3d5d6828a8eff24"

PV = "${MAJOR_VER}.${MINOR_VER}.${PATCH_VER}"
#BRANCH = "release/${MAJOR_VER}.x"
BRANCH = "ohos-${MAJOR_VER}"

LLVMMD5SUM = "8a15a0759ef07f2682d2ba4b893c9afe"
CLANGMD5SUM = "ff42885ed2ab98f1ecb8c1fc41205343"
LLDMD5SUM = "ae7dc7c027b1fa89b5b013d391d3ee2b"
LLDBMD5SUM = "2e0d44968471fcde980034dbb826bea9"

LLVM_LIBDIR_SUFFIX="${@d.getVar('baselib').replace('lib', '')}"

# set the default pigz thread
export PIGZ = "-p ${@oe.utils.cpu_count(at_least=2)}"

require common.inc