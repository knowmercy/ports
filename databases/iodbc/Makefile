# $OpenBSD: Makefile,v 1.41 2017/11/02 21:51:59 naddy Exp $

COMMENT-main=		ODBC 3.x driver manager
COMMENT-admin=		ODBC 3.x driver manager admin application

V=			3.52.10

DISTNAME=		libiodbc-$V
PKGNAME=		iodbc-$V
PKGNAME-main=		iodbc-$V
PKGNAME-admin=		iodbc-admin-$V
REVISION-main=		0
REVISION-admin=		1

CATEGORIES=		databases

SHARED_LIBS +=		iodbcinst	3.15
SHARED_LIBS +=		iodbc		3.16
SHARED_LIBS +=		iodbcadm	3.15
SHARED_LIBS +=		drvproxy	3.15

HOMEPAGE=		http://www.iodbc.org/

MAINTAINER=		Stuart Henderson <sthen@openbsd.org>

# Dual licensed: BSD or LGPLv2
PERMIT_PACKAGE_CDROM=	yes

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=iodbc/}

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--with-iodbc-inidir="${SYSCONFDIR}/iodbc" \
			--disable-libodbc

MULTI_PACKAGES=		-main -admin

WANTLIB-main=		c pthread

LIB_DEPENDS-admin=	databases/iodbc,-main \
			x11/gtk+2

LIB_DEPENDS-main=	# empty

WANTLIB-admin += X11 Xcomposite Xcursor Xdamage Xext Xfixes Xi Xinerama
WANTLIB-admin += Xrandr Xrender atk-1.0 c cairo expat ffi fontconfig
WANTLIB-admin += freetype gdk-x11-2.0 gdk_pixbuf-2.0 gio-2.0 glib-2.0
WANTLIB-admin += gmodule-2.0 gobject-2.0 graphite2 gthread-2.0 gtk-x11-2.0
WANTLIB-admin += harfbuzz iconv intl iodbc iodbcinst m pango-1.0 pangocairo-1.0
WANTLIB-admin += pangoft2-1.0 pcre pixman-1 png pthread
WANTLIB-admin += xcb xcb-render xcb-shm z

EXDIR=${PREFIX}/share/examples/iodbc/
post-install:
	${INSTALL_DATA_DIR} ${EXDIR}
	${SUBST_DATA} \
	    ${WRKSRC}/etc/odbc.ini.sample ${EXDIR}/odbc.ini.sample \
	    ${WRKSRC}/etc/odbcinst.ini.sample ${EXDIR}/odbcinst.ini.sample
	rm -f ${PREFIX}/man/man1/iodbctestw.1
	ln ${PREFIX}/man/man1/iodbctest.1 ${PREFIX}/man/man1/iodbctestw.1

.include <bsd.port.mk>
