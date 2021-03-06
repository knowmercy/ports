# $OpenBSD: Makefile,v 1.40 2017/11/02 13:06:22 ajacoutot Exp $

# XXX change proxy settings without network-manager?

COMMENT=		GNOME control center

GNOME_PROJECT=		gnome-control-center
GNOME_VERSION=		3.26.2

CATEGORIES=		x11

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += FLAC ICE SM X11 X11-xcb Xau Xcomposite Xcursor Xdamage
WANTLIB += Xext Xfixes Xi Xinerama Xrandr Xrender Xtst Xxf86vm
WANTLIB += accountsservice atk-1.0 atk-bridge-2.0 atspi avahi-common
WANTLIB += c cairo cairo-gobject canberra canberra-gtk3 colord
WANTLIB += colord-gtk colordprivate crack crypto cups unistring
WANTLIB += dbus-1 drm epoxy execinfo expat ffi fontconfig
WANTLIB += freetype gbm gcrypt gdk-3 gdk_pixbuf-2.0 gio-2.0
WANTLIB += glapi glib-2.0 gmodule-2.0 gmp gnome-desktop-3 goa-1.0
WANTLIB += goa-backend-1.0 gobject-2.0 gpg-error graphite2 grilo-0.3
WANTLIB += gstaudio-1.0 gstbase-1.0 gstreamer-1.0 gsttag-1.0 gstvideo-1.0
WANTLIB += gthread-2.0 gtk-3 gtop-2.0 harfbuzz hogweed ibus-1.0
WANTLIB += iconv icudata icuuc idn2 intl javascriptcoregtk-4.0
WANTLIB += json-glib-1.0 kvm lber-2.4 lcms2 ltdl lzma m
WANTLIB += nettle ogg orc-0.4 p11-kit pango-1.0 pangocairo-1.0
WANTLIB += pangoft2-1.0 pcre pixman-1 png polkit-gobject-1
WANTLIB += pulse pulse-mainloop-glib pwquality rest-0.7
WANTLIB += sasl2 secret-1 smbclient sndfile soup-2.4 soup-gnome-2.4
WANTLIB += sqlite3 ssl ${COMPILER_LIBCXX} tasn1 upower-glib
WANTLIB += vorbis vorbisenc vorbisfile webkit2gtk-4.0 xcb xcb-dri2
WANTLIB += EGL GL GLESv2 gstallocators-1.0 gstbadallocators-1.0
WANTLIB += xcb-glx xcb-render xcb-shm xcb-xfixes xml2 z
WANTLIB += heimdal/lib/heimsqlite

MODULES=		security/heimdal \
			x11/gnome

LIB_DEPENDS=		audio/pulseaudio \
			audio/libcanberra,-gtk3 \
			devel/libgtop2 \
			graphics/colord-gtk \
			net/samba \
			print/cups,-libs \
			security/libpwquality \
			sysutils/accountsservice \
			sysutils/upower \
			x11/gnome/desktop \
			x11/gnome/grilo \
			x11/gnome/online-accounts

BUILD_DEPENDS=		x11/gnome/settings-daemon \
			devel/iso-codes \
			devel/gsettings-desktop-schemas

RUN_DEPENDS=		x11/gnome/settings-daemon \
			devel/iso-codes \
			devel/gsettings-desktop-schemas

# NOTE that a11y dependencies (e.g. mousetweaks, caribou...) are not
# enforced on purpose.

# polkit(8) almost always needs to know the "active" session
RUN_DEPENDS +=	sysutils/consolekit

# needed for gnome-color-panel
RUN_DEPENDS +=		x11/gnome/color-manager

# needed for gnome-power-panel+gnome-screen-panel
RUN_DEPENDS +=		x11/gnome/power-manager

# needed for gnome-printers-panel
RUN_DEPENDS +=		print/cups-pk-helper \
			print/system-config-printer

# gkbd-keyboard-display
RUN_DEPENDS +=		x11/gnome/libgnomekbd

# calls grl_registry_load...plugin
RUN_DEPENDS +=		x11/gnome/grilo-plugins

# needed for gnome-region-panel; optional and would create a cyclic dep:
# gnome-session -> gnome-shell -> gnome-control-center -> gnome-session
#RUN_DEPENDS +=		x11/gnome/session

MODGNOME_TOOLS += desktop-file-utils docbook gtk-update-icon-cache yelp
MODGNOME_CPPFLAGS=	-I${X11BASE}/include
MODGNOME_LDFLAGS=	-L${X11BASE}/lib

FAKE_FLAGS=		sysconfdir=${PREFIX}/share/examples/gnome-control-center

CONFIGURE_STYLE=	gnu

###
AUTOCONF_VERSION=	2.69
AUTOMAKE_VERSION=	1.15
BUILD_DEPENDS +=	${MODGNU_AUTOCONF_DEPENDS} \
			${MODGNU_AUTOMAKE_DEPENDS} \
			devel/libtool # libtoolize

pre-configure:
	cd ${WRKSRC} && ${SETENV} \
		AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		AUTOMAKE_VERSION=${AUTOMAKE_VERSION} \
		autoreconf -fi
###

	${SUBST_CMD} ${WRKSRC}/panels/printers/pp-host.c

.include <bsd.port.mk>
