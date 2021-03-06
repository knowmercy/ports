# $OpenBSD: Makefile,v 1.235 2017/11/09 19:44:12 landry Exp $

# XXX add libphonenumber support when a cpp release is out

COMMENT=		unified backend for PIM programs

GNOME_PROJECT=		evolution-data-server
GNOME_VERSION=		3.26.2.1
REVISION=		1

CATEGORIES=		databases productivity

SHARED_LIBS +=  camel-1.2            39.1
SHARED_LIBS +=  edataserver-1.2      20.2
SHARED_LIBS +=  ebackend-1.2         6.1
SHARED_LIBS +=  edataserverui-1.2    2.1
SHARED_LIBS +=  ebook-contacts-1.2   3.1
SHARED_LIBS +=  edata-book-1.2       17.1
SHARED_LIBS +=  ebook-1.2            20.1
SHARED_LIBS +=  ecal-1.2             17.1
SHARED_LIBS +=  edata-cal-1.2        20.1

MAINTAINER=	Jasper Lievisse Adriaanse <jasper@openbsd.org>, \
		Antoine Jacoutot <ajacoutot@openbsd.org>

# LGPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += atk-1.0 c cairo cairo-gobject db gck-1 gcr-base-3 gcr-ui-3
WANTLIB += gdata gdk-3 gdk_pixbuf-2.0 gio-2.0 glib-2.0 gmodule-2.0
WANTLIB += goa-1.0 gobject-2.0 gtk-3 gweather-3 ical icalss icalvcal
WANTLIB += icudata icui18n icuuc intl javascriptcoregtk-4.0 json-glib-1.0
WANTLIB += lber ldap m nspr4 nss3 p11-kit pango-1.0 pangocairo-1.0
WANTLIB += plc4 plds4 pthread secret-1 smime3 nssutil3 soup-2.4
WANTLIB += sqlite3 ssl3 ${COMPILER_LIBCXX} webkit2gtk-4.0 xml2 z

MODULES=		devel/cmake \
			devel/dconf \
			lang/python \
			x11/gnome

BUILD_DEPENDS=		devel/gperf

LIB_DEPENDS= 		databases/db/v4 \
			databases/openldap \
			devel/libgdata \
			textproc/libical \
			www/webkitgtk4 \
			x11/gnome/gcr \
			x11/gnome/libgweather \
			x11/gnome/online-accounts

MODPY_RUNDEP=		No
MODGNOME_TOOLS=		gobject-introspection vala

MODGNOME_LDFLAGS=	-L${X11BASE}/lib

CONFIGURE_ARGS=		-DWITH_KRB5=OFF \
			-DWITH_LIBDB_CFLAGS="-I${LOCALBASE}/include/db4" \
			-DWITH_LIBDB_LIBS="-L${LOCALBASE}/lib -ldb" \
			-DWITH_OPENLDAP=${LOCALBASE} \
			-DCMAKE_C_FLAGS="-I${LOCALBASE}/include"


# needs signond, libsignon-glib -- Ubuntu/Meego
CONFIGURE_ARGS +=	-DENABLE_UOA=OFF

pre-configure:
	sed -i 's,/usr/sbin/imapd,${LOCALBASE}/libexec/imapd,g' \
		${WRKSRC}/src/camel/providers/imapx/camel-imapx-settings.c

.include <bsd.port.mk>
