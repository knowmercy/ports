# $OpenBSD: Makefile,v 1.7 2017/11/01 21:44:44 jeremy Exp $

BROKEN-sparc64 =	Bus error (core dumped)

COMMENT =		lightweight, embeddable implementation of ruby

VERSION =		1.3.0
DISTNAME =		mruby-${VERSION}
CATEGORIES =		lang
HOMEPAGE =		https://github.com/mruby/mruby

# MIT
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += c m ncurses readline termcap

MASTER_SITES =		https://github.com/mruby/mruby/archive/
DISTFILES =		${DISTNAME}-${VERSION}.tar.gz{${VERSION}.tar.gz}

MODULES =		lang/ruby
BUILD_DEPENDS =		devel/bison \
			lang/ruby/${MODRUBY_REV}

MAKE_ENV =		CC="${CC}" \
			LD="${CC}"

NO_CONFIGURE =		Yes
SUBST_VARS =		RUBY

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${RUBY} ./minirake --verbose

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/{lib,include,share/doc}/mruby/ 
	cp -R ${WRKSRC}/mrb{lib,gems} ${PREFIX}/lib/mruby/
	cp -R ${WRKSRC}/include/* ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/doc/guides/* ${PREFIX}/share/doc/mruby/ 

do-test:
	${SUBST_CMD} ${WRKSRC}/tasks/mruby_build.rake
	cd ${WRKSRC} && ${RUBY} ./minirake test

.include <bsd.port.mk>
