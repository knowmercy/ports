# $OpenBSD: Makefile,v 1.155 2017/11/09 19:44:12 landry Exp $

USE_WXNEEDED=		Yes

COMMENT=		next generation GNOME shell

GNOME_PROJECT=		gnome-shell
GNOME_VERSION=		3.26.2
REVISION=		0

# GPLv2+
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += EGL FLAC ICE SM X11 X11-xcb Xcomposite Xcursor Xdamage
WANTLIB += Xext Xfixes Xi Xinerama Xrandr Xrender Xtst Xxf86vm
WANTLIB += atk-1.0 atk-bridge-2.0 atspi c cairo cairo-gobject
WANTLIB += camel-1.2 canberra canberra-gtk3 croco-0.6 dbus-1 drm
WANTLIB += ecal-1.2 edataserver-1.2 epoxy execinfo expat ffi fontconfig
WANTLIB += freetype gbm gck-1 gcr-base-3 gcrypt gdk-3 gdk_pixbuf-2.0
WANTLIB += gio-2.0 girepository-1.0 gjs glapi glib-2.0 gmodule-2.0
WANTLIB += gnome-desktop-3 gobject-2.0 gpg-error graphite2 gstaudio-1.0
WANTLIB += gstbase-1.0 gstreamer-1.0 gsttag-1.0 gstvideo-1.0 gthread-2.0
WANTLIB += gtk-3 harfbuzz ical icalss icalvcal iconv icudata icui18n
WANTLIB += icuuc intl javascriptcoregtk-4.0 json-glib-1.0 ltdl
WANTLIB += lzma m mozjs-52 ncursesw nspr4 nss3 ogg orc-0.4
WANTLIB += p11-kit pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre
WANTLIB += pixman-1 plc4 plds4 png polkit-agent-1 polkit-gobject-1
WANTLIB += pthread pulse pulse-mainloop-glib readline
WANTLIB += secret-1 smime3 sndfile soup-2.4 sqlite3 ssl3
WANTLIB += startup-notification-1 upower-glib vorbis
WANTLIB += vorbisenc vorbisfile webkit2gtk-4.0 xcb xcb-dri2 xcb-glx
WANTLIB += xcb-randr xcb-render xcb-res xcb-shm xcb-util xcb-xfixes
WANTLIB += xcb-xkb xkbcommon xkbcommon-x11 xkbfile xml2 z
WANTLIB += GL Xt enchant gstapp-1.0 gstfft-1.0 gstpbutils-1.0
WANTLIB += hyphen jpeg notify nssutil3 ${COMPILER_LIBCXX} webp xslt
WANTLIB += GLESv2 gstallocators-1.0 gstbadallocators-1.0 gstgl-1.0
WANTLIB += harfbuzz-icu tasn1 mutter-1

MODULES=		devel/dconf \
			devel/meson \
			lang/python \
			x11/gnome

# sync with x11/gnome/gjs
COMPILER=		base-clang ports-clang ports-gcc

MODPY_VERSION=		${MODPY_DEFAULT_VERSION_3}

MODGNOME_TOOLS +=	desktop-file-utils docbook gobject-introspection

BUILD_DEPENDS +=	devel/gsettings-desktop-schemas
RUN_DEPENDS +=		devel/gsettings-desktop-schemas

LIB_DEPENDS=		audio/pulseaudio \
			databases/evolution-data-server \
			multimedia/gstreamer1/core \
			sysutils/polkit \
			www/libcroco \
			x11/gnome/gcr \
			x11/gnome/gjs \
			x11/gnome/mutter

# configure looks for gnome-keybindings.pc;
# system.js, backgroundMenu.js, network.js, remoteSearch.js
BUILD_DEPENDS +=	x11/gnome/control-center
RUN_DEPENDS +=		x11/gnome/control-center

# onscreen keyboard
BUILD_DEPENDS +=	x11/gnome/caribou
RUN_DEPENDS +=		x11/gnome/caribou

# polkit(8) almost always needs to know the "active" session
RUN_DEPENDS +=		sysutils/consolekit

# gnome-shell-extension-tool, gnome-shell-perf-tool
RUN_DEPENDS +=		devel/py-gobject3,python3

# Don't depend on evolution to lower down the amount of dependencies and
# because most users want to be able to choose their PIM. Evolution can
# be installed separately or as part of the "gnome-extra" meta-package.
#RUN_DEPENDS +=		mail/evolution

# polkitAgent.js, endSessionDialog.js, screenShield.js, status/system.js,
# unlockDialog.js, userWidget.js
RUN_DEPENDS +=		sysutils/accountsservice

# dateMenu.js
RUN_DEPENDS +=		x11/gnome/clocks

# telepathyClient.js
RUN_DEPENDS +=		net/telepathy/telepathy-logger

# yelp.desktop menu entry (from yelp: OnlyShowIn=GNOME;Unity;)
# prevents => The URI "help:gnome-help/index" does not point to a valid page.
RUN_DEPENDS +=		x11/gnome/user-docs

# gkbd-keyboard-display
RUN_DEPENDS +=		x11/gnome/libgnomekbd

# add required introspection libs that are not in the dependency chain
RUN_DEPENDS +=		inputmethods/ibus \
			x11/gnome/gdm

MODGNOME_LDFLAGS +=	-L${X11BASE}/lib

# XXX: needed for g-ir-scanner(1)
MAKE_ENV +=		${_MODGNOME_ldflags}

# /gnome-shell-3.18.4_writes_to_HOME
PORTHOME=		${WRKDIR}

.include <bsd.port.arch.mk>

# XXX: https://bugzilla.gnome.org/show_bug.cgi?id=789937
# Generate this file upfront as it may not be created in time
# due to ninja's randomization.
pre-build:
	exec ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/ninja -C ${WRKBUILD} -v src/st/st-scroll-view-fade-generated.c

.include <bsd.port.mk>
