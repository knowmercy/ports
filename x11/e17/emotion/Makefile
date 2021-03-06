# $OpenBSD: Makefile,v 1.26 2017/10/23 17:11:03 sthen Exp $

COMMENT =		video (and audio) codec playback library

DISTNAME =		emotion-1.7.10
REVISION =		7

SHARED_LIBS +=	emotion                   2.0 # 8.10

# BSD
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += ${MODLUA_WANTLIB}
WANTLIB += X11 Xcomposite Xcursor Xdamage Xext Xfixes Xi Xinerama Xrandr
WANTLIB += Xrender Xss Xtst c cares crypto curl ecore ecore_con
WANTLIB += ecore_evas ecore_file ecore_imf ecore_imf_evas ecore_input
WANTLIB += ecore_input_evas ecore_ipc ecore_x edje eet eina eio embryo
WANTLIB += evas expat ffi fontconfig freetype fribidi glib-2.0
WANTLIB += gmodule-2.0 gobject-2.0 graphite2 gstbase-0.10
WANTLIB += gstinterfaces-0.10 gstreamer-0.10 gstvideo-0.10 gthread-2.0
WANTLIB += harfbuzz jpeg lzma m nghttp2 orc-0.4 pcre pthread
WANTLIB += ssl xcb xml2 z

MODULES =		devel/gettext \
			lang/lua \
			x11/e17

MODE17_PURGE_LA =	lib/edje/modules/emotion

LIB_DEPENDS =		devel/orc \
			multimedia/gstreamer-0.10/plugins-base \
			x11/e17/ecore>=1.7.10v2 \
			x11/e17/edje>=1.7.10v2 \
			x11/e17/embryo>=1.7.10v2

CONFIGURE_ARGS +=	--disable-doc \
			--disable-xine \
			--disable-generic-vlc

.include <bsd.port.mk>
