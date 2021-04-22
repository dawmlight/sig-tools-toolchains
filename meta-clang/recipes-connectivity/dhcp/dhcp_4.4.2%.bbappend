FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI_append_toolchain-clang = "\
    file://dhcp-4.4.2-clang-12.patch \
"
