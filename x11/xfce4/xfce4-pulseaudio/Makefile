# $OpenBSD: Makefile,v 1.14 2017/10/29 16:30:22 landry Exp $

COMMENT=	Xfce4 pulseaudio control line panel plugin

XFCE_VERSION=	0.3.2
XFCE_PLUGIN=	pulseaudio

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

MODXFCE_WANTLIB =	xfce4panel-2.0
WANTLIB += FLAC ICE SM X11 X11-xcb Xcomposite Xcursor Xdamage Xext
WANTLIB += Xfixes Xi Xinerama Xrandr Xrender Xtst atk-1.0 atk-bridge-2.0
WANTLIB += atspi cairo cairo-gobject dbus-1 epoxy execinfo
WANTLIB += expat ffi fontconfig freetype gdk-3 gdk_pixbuf-2.0
WANTLIB += gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0 graphite2
WANTLIB += gthread-2.0 gtk-3 harfbuzz m ogg pango-1.0
WANTLIB += pangocairo-1.0 pangoft2-1.0 pcre pixman-1 png pthread
WANTLIB += pulse pulse-mainloop-glib sndfile
WANTLIB += startup-notification-1 vorbis vorbisenc xcb xcb-render
WANTLIB += xcb-shm xcb-util xfce4ui-2 xfce4util xfconf-0
WANTLIB += z notify iconv intl dbus-glib-1

MODULES=	x11/xfce4

LIB_DEPENDS+=	audio/pulseaudio devel/libnotify

.include <bsd.port.mk>
