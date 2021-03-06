# $OpenBSD: Makefile,v 1.6 2016/06/09 13:54:34 kirby Exp $

COMMENT =		birthday reminder with tray notification

GH_ACCOUNT = 		lafrech
GH_PROJECT =		gbirthday
GH_TAGNAME = 		v0.6.10

CATEGORIES =		productivity x11

HOMEPAGE =		http://gbirthday.sourceforge.net/

MAINTAINER =		Kirill Bychkov <kirby@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/python
RUN_DEPENDS =		devel/desktop-file-utils \
			devel/py-notify \
			x11/gtk+3,-guic \
			x11/py-gtk2
NO_TEST =		Yes

MODPY_ADJ_FILES += 	src/gb

PKG_ARCH = 		*

post-patch:
	sed -i 's,_Comment,Comment,' ${WRKSRC}/gbirthday.desktop.in
	sed -i 's,@VER@,${GH_TAGNAME:S/v//},g' ${WRKSRC}/src/gbirthday/__init__.py


do-build:
	# dummy. cannot be "NO_BUILD" as that zaps BUILD_DEPENDS.

pre-install:
	find ${WRKSRC} -name \*.orig -exec rm {} \;

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/gb ${PREFIX}/bin/gbirthday
	${INSTALL_DATA_DIR} ${PREFIX}/lib/python${MODPY_VERSION}/site-packages/
	cd ${WRKSRC}/src/ && pax -rw gbirthday \
		${PREFIX}/lib/python${MODPY_VERSION}/site-packages/
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/gbirthday.desktop.in \
		${PREFIX}/share/applications/gbirthday.desktop
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/hicolor/scalable/apps/
	${INSTALL_DATA} ${WRKSRC}/pics/gbirthday.svg \
		${PREFIX}/share/icons/hicolor/scalable/apps/

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/lib/python${MODPY_VERSION}/site-packages/gbirthday

.include <bsd.port.mk>
