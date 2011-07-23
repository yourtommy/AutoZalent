#message ("common.pri is included")

isEmpty(ROOTDIR) {
    warning("ROOTDIR is not set")
} else {
    SOURCEDIR = $$join(ROOTDIR,,,Source/)
    BINARYDIR = $$join(ROOTDIR,,,Binary/)
    #LIBDIR = $$join(BINARYDIR,,,Lib/)
    BINDIR = $$join(BINARYDIR,,,Bin/)
    OBJDIR = $$join(BINARYDIR,,,Intermediate/)
    GENDIR = $$join(BINARYDIR,,,GeneratedFiles/)

    #TODO: support x64 platform
    debug {
        CONFIG_SUFFIX = x86/debug/
    } else : release {
        CONFIG_SUFFIX = x86/release/
    }

    isEmpty(DESTDIR) : DESTDIR = $$join(BINDIR,,,$$CONFIG_SUFFIX)
    OBJECTS_DIR = $$join(OBJDIR,,,$$CONFIG_SUFFIX)
    MOC_DIR = $$join(GENDIR,,,$$CONFIG_SUFFIX)
    UI_DIR = $$join(GENDIR,,,$$CONFIG_SUFFIX)
    RCC_DIR = $$join(GENDIR,,,$$CONFIG_SUFFIX)
    #DLLDESTDIR = $$join(BINDIR,,,$$CONFIG_SUFFIX)

    INCLUDEPATH += $$join(SOURCEDIR,,,Common/Include/)
    INCLUDEPATH += $$MOC_DIR
    INCLUDEPATH += $$UI_DIR
    INCLUDEPATH += $$RCC_DIR
}
