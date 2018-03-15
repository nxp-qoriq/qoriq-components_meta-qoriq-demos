DESCRIPTION = "Secure Object"
LICENSE = "BSD"

DEPENDS = "openssl optee-os-qoriq optee-client-qoriq"
RDEPENDS_${PN} = "bash libcrypto libssl python"

DEPENDS += "python-pycrypto-native"

inherit pythonnative

LDFLAGS += "${TOOLCHAIN_OPTIONS}"

SRC_URI = "git://bitbucket.sw.nxp.com/scm/dndev/secure_obj.git;protocol=http \
"
SRCREV = "0f75291d113b212d28147bbfe6deea14654c63e3"

WRAP_TARGET_PREFIX ?= "${TARGET_PREFIX}"
export SECURE_STORAGE_PATH = "${S}/secure_storage_ta/ta/"
export OPTEE_CLIENT_EXPORT = "${RECIPE_SYSROOT}/usr"

EXTRA_OEMAKE = 'CC="${CC}" LD="${CC}"'

ALLOW_EMPTY_${PN} = "1"
INHIBIT_PACKAGE_STRIP = "1"
PARALLEL_MAKE = ""
INSANE_SKIP_${PN} = "ldflags"
COMPATIBLE_MACHINE = "(ls2080ardb|ls2084ardb|ls2088a|ls1043a|ls1046a|ls1088a)"