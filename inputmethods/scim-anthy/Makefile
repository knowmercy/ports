# $OpenBSD: Makefile,v 1.20 2017/10/23 17:10:51 sthen Exp $

COMMENT =	scim input method module for anthy

DISTNAME =	scim-anthy-1.2.7

REVISION =	8

CATEGORIES =	inputmethods japanese

HOMEPAGE =	https://osdn.jp/projects/scim-imengine/

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += GL X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes Xi
WANTLIB += Xinerama Xrandr Xrender Xxf86vm anthy anthydic atk-1.0 cairo
WANTLIB += drm expat ffi fontconfig freetype gdk-x11-2.0 gdk_pixbuf-2.0
WANTLIB += gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0 graphite2
WANTLIB += gthread-2.0 gtk-x11-2.0 harfbuzz m pango-1.0 pangocairo-1.0
WANTLIB += pangoft2-1.0 pcre pixman-1 png pthread
WANTLIB += scim-1.0 scim-gtkutils-1.0 scim-x11utils-1.0 ${COMPILER_LIBCXX} xcb
WANTLIB += xcb-render xcb-shm z

MASTER_SITES =	${MASTER_SITE_OSDN_JP:=scim-imengine/37309/}

MODULES =	devel/gettext

LIB_DEPENDS =	inputmethods/anthy \
		inputmethods/scim

LIBTOOL_FLAGS =	--tag=disable-static

CONFIGURE_STYLE = gnu

.include <bsd.port.mk>
