# $OpenBSD: Makefile,v 1.25 2017/10/23 17:11:05 sthen Exp $

COMMENT=	GDI+ comptible API

DISTNAME=	libgdiplus-4.2
REVISION=	2

CATEGORIES=	x11 devel

SHARED_LIBS +=	gdiplus	2.0	# .0.0

HOMEPAGE=	http://www.mono-project.com/Libgdiplus

MAINTAINER=	Robert Nagy <robert@openbsd.org>

# GPLv2 and Mozilla Public License 1.1
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += X11 Xext Xrender cairo exif expat ffi fontconfig freetype
WANTLIB += gif glib-2.0 gobject-2.0 graphite2 gthread-2.0 harfbuzz
WANTLIB += iconv intl jpeg m pango-1.0 pangocairo-1.0 pangoft2-1.0
WANTLIB += pcre pixman-1 png pthread tiff xcb xcb-render
WANTLIB += xcb-shm z

MASTER_SITES=	http://download.mono-project.com/sources/libgdiplus/

LIB_DEPENDS=	devel/gettext \
		devel/pango \
		graphics/tiff \
		graphics/libexif \
		graphics/giflib

CONFIGURE_STYLE=autoconf
AUTOCONF_VERSION=2.69

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include"
CONFIGURE_ARGS=	--with-pango

.include <bsd.port.mk>
