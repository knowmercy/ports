# $OpenBSD: Makefile,v 1.100 2017/11/09 19:44:12 landry Exp $

# XXX: PORTROACH set below to override the value from gnome.port.mk

COMMENT=		people aggregation library

GNOME_PROJECT=		folks
GNOME_VERSION=		0.11.4
REVISION=		5

# MODULE_VERSION in config.h
API_V=			43

SHARED_LIBS +=  folks                5.5      # 43.3
SHARED_LIBS +=  folks-dummy          0.0      # 43.3
SHARED_LIBS +=  folks-telepathy      5.2      # 43.3
SHARED_LIBS +=  folks-eds            1.2      # 43.3

SUBST_VARS=		API_V

HOMEPAGE=		https://wiki.gnome.org/Projects/Folks

WANTLIB += EGL GL ICE SM X11 X11-xcb Xcomposite Xcursor Xdamage
WANTLIB += Xext Xfixes Xi Xinerama Xrandr Xrender Xt Xxf86vm atk-1.0
WANTLIB += atk-bridge-2.0 atspi c cairo cairo-gobject camel-1.2
WANTLIB += db dbus-1 dbus-glib-1 drm ebackend-1.2 ebook-1.2 ebook-contacts-1.2
WANTLIB += edata-book-1.2 edataserver-1.2 enchant epoxy $(LIBECXX)
WANTLIB += expat ffi fontconfig freetype gbm gck-1 gcr-base-3
WANTLIB += gcrypt gdk-3 gdk_pixbuf-2.0 gee-0.8 gio-2.0 glapi glib-2.0
WANTLIB += gmodule-2.0 gobject-2.0 gpg-error graphite2 gstapp-1.0
WANTLIB += gstaudio-1.0 gstbase-1.0 gstfft-1.0 gstpbutils-1.0
WANTLIB += gstreamer-1.0 gsttag-1.0 gstvideo-1.0 gthread-2.0 gtk-3
WANTLIB += harfbuzz harfbuzz-icu hyphen iconv icudata icui18n
WANTLIB += icuuc intl javascriptcoregtk-4.0 jpeg json-glib-1.0
WANTLIB += lzma m ncurses notify nspr4 nss3 nssutil3 orc-0.4 p11-kit
WANTLIB += pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre pixman-1
WANTLIB += plc4 plds4 png pthread readline secret-1
WANTLIB += smime3 soup-2.4 sqlite3 ssl3 telepathy-glib
WANTLIB += webkit2gtk-4.0 webp xcb xcb-dri2 xcb-glx xcb-render
WANTLIB += xcb-shm xcb-xfixes xml2 xslt z
WANTLIB += GLESv2 gstallocators-1.0 gstbadallocators-1.0 gstgl-1.0
WANTLIB += tasn1

MODULES=		devel/dconf \
			x11/gnome

LIB_DEPENDS=		databases/evolution-data-server \
			devel/libgee \
			net/telepathy/telepathy-glib

# needed at runtime by the telepathy backend (AccountManager)
RUN_DEPENDS=		net/telepathy/telepathy-mission-control

TEST_DEPENDS=		${FULLPKGNAME}:${BASE_PKGPATH}

MODGNOME_TOOLS +=	gobject-introspection vala
MODGNOME_CPPFLAGS +=	-L${X11BASE}/lib

# requires libofono (not ported)
CONFIGURE_ARGS += 	--disable-ofono-backend

# no Bluez stack on OpenBSD
CONFIGURE_ARGS +=	--disable-bluez-backend

# https://git.gnome.org/browse/folks/commit/Makefile.am?id=8ebe13c457660de380521874a006425083151741
CONFIGURE_ARGS += 	--disable-fatal-warnings

post-install:
	rm ${PREFIX}/lib/folks/${API_V}/backends/*/*.{a,la}

.include <bsd.port.mk>

PORTROACH=	# empty
