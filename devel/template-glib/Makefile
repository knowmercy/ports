# $OpenBSD: Makefile,v 1.2 2017/11/04 11:57:54 ajacoutot Exp $

COMMENT=		templating library for GLib

GNOME_PROJECT=		template-glib
GNOME_VERSION=		3.26.1

SHARED_LIBS +=  template_glib-1.0         0.0 # 0.0

CATEGORIES=		devel

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# LGPLv2.1
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += gio-2.0 girepository-1.0 glib-2.0 gobject-2.0 intl
WANTLIB += m

MODULES=		devel/meson \
			x11/gnome

MODGNOME_TOOLS=		gobject-introspection vala

BUILD_DEPENDS=		devel/bison

LIB_DEPENDS=		devel/gobject-introspection

.include <bsd.port.mk>
