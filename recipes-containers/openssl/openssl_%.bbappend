RCREV = "894da2fb7ed5d314ee5c2fc9fd2d9b8b74111596"

do_install_append () {
    cp --dereference -R crypto  ${D}${includedir}
}
