#message ("common.pri is included")

isEmpty(ROOTDIR) {
    warning("ROOTDIR is not set")
} else {
    SOURCEDIR = $$join(ROOTDIR,,,Source/)
    BINARYDIR = $$join(ROOTDIR,,,Binary/)
    #LIBDIR = $$join(BINARYDIR,,,Lib/)
    BINDIR = $$join(BINARYDIR,,,Bin/)

    #TODO: support x64 platform
    debug {
        isEmpty(DESTDIR) : DESTDIR = $$join(BINDIR,,,x86/debug)
        #DLLDESTDIR = $$join(BINDIR,,,x86/debug)
    } else : release {
        isEmpty(DESTDIR) : DESTDIR = $$join(BINDIR,,,x86/release)
        #DLLDESTDIR = $$join(BINDIR,,,x86/release)
    }

    #message($$join(DESTDIR,,DESTDIR is set to: ,))
    #message($$join(DLLDESTDIR,,DLLDESTDIR is set to: ,))
}
