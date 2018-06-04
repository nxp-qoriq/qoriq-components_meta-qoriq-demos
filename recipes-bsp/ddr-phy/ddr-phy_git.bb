SUMMARY = "DDR firmware repository"
LICENSE = "NXP-Binary-EULA"
LIC_FILES_CHKSUM = "file://NXP-Binary-EULA.txt;md5=89cc852481956e861228286ac7430d74"

inherit deploy

SRC_URI = "git://bitbucket.sw.nxp.com/scm/dnnpi/ddr-phy-binary.git;branch=master;protocol=https"
SRCREV = "4081187e76c634366c09d8631f9739c80cc20366"

S = "${WORKDIR}/git"

REGLEX_lx2160a = "lx2160a"

do_install () {
    install -d ${D}/boot
    install -m 755 ${S}/${REGLEX}/*.itb ${D}/boot
}

do_deploy () {
    install -d ${DEPLOYDIR}/ddr-phy
    install -m 755 ${S}/${REGLEX}/*.itb ${DEPLOYDIR}/ddr-phy
}
addtask deploy before do_build after do_install

PACKAGES += "${PN}-image"
FILES_${PN}-image += "/boot"

COMPATIBLE_MACHINE = "(lx2160a)"
PACKAGE_ARCH = "${MACHINE_ARCH}"