# $OpenBSD: Makefile,v 1.16 2017/10/31 07:22:03 ajacoutot Exp $

COMMENT=		library to use HTTPSEverywhere in desktop applications

GNOME_VERSION=		0.6.3
GNOME_PROJECT=		libhttpseverywhere

SHARED_LIBS=		httpseverywhere-0.6 0.0

CATEGORIES=		security net

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# LGPLv3
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += archive gee-0.8 gio-2.0 glib-2.0 gobject-2.0 json-glib-1.0
WANTLIB += soup-2.4

MODULES=		devel/meson \
			x11/gnome

MODGNOME_TOOLS=		gobject-introspection vala

LIB_DEPENDS=		archivers/libarchive \
			devel/json-glib \
			devel/libgee \
			devel/libsoup

.include <bsd.port.mk>
