# $OpenBSD: Makefile,v 1.20 2017/10/23 17:10:51 sthen Exp $

COMMENT=	scim input method module for pinyin

DISTNAME=	scim-pinyin-0.5.91
REVISION=	10

CATEGORIES=	inputmethods chinese

HOMEPAGE=	https://github.com/scim-im/scim-pinyin

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB+= GL X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes Xi
WANTLIB+= Xinerama Xrandr Xrender Xxf86vm atk-1.0 cairo drm expat ffi
WANTLIB+= fontconfig freetype gdk-x11-2.0 gdk-x11-2.0 gdk_pixbuf-2.0
WANTLIB+= gdk_pixbuf-2.0 gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0
WANTLIB+= graphite2 gthread-2.0 gtk-x11-2.0 gtk-x11-2.0 harfbuzz m
WANTLIB+= pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre pixman-1 png
WANTLIB+= pthread scim-1.0 scim-gtkutils-1.0
WANTLIB+= scim-x11utils-1.0 ${COMPILER_LIBCXX} xcb xcb-render xcb-shm z

MODULES=	devel/gettext

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scim/}

LIB_DEPENDS=	x11/gtk+2 \
		inputmethods/scim

LIBTOOL_FLAGS=	--tag=disable-static

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	--disable-static \
		--disable-skim-support

.include <bsd.port.mk>
