# $OpenBSD: Makefile,v 1.26 2017/10/23 17:11:03 sthen Exp $

COMMENT=		wm-dockapp; shows rotating 3d-object and CPU load

DISTNAME=		wmcube-0.98
REVISION=		3
CATEGORIES=		sysutils x11 x11/windowmaker

HOMEPAGE=		http://kling.mine.nu/wmcube.htm

# GPL
PERMIT_PACKAGE_CDROM=	Yes
WANTLIB=		X11 Xext Xpm c m xcb

MASTER_SITES=		http://kling.mine.nu/files/

NO_TEST=		Yes

MAKE_FLAGS=		CC="${CC}"
MAKE_FILE=		Makefile.OPENBSD
WRKDIST=		${WRKDIR}/wmcube
WRKSRC=			${WRKDIST}/wmcube

3D_OBJECTS=		${PREFIX}/share/wmcube

post-install:
	${INSTALL_DATA_DIR} ${3D_OBJECTS}
	${INSTALL_DATA} ${WRKDIST}/3dObjects/* ${3D_OBJECTS}

.include <bsd.port.mk>
