# $OpenBSD: Makefile,v 1.19 2017/08/22 05:19:17 kirby Exp $

COMMENT =		seafile client

GH_PROJECT = 		seafile-client

WANTLIB += Qt5Core Qt5Gui Qt5Network Qt5Widgets c ccnet
WANTLIB += crypto event_core event_extra gio-2.0 glib-2.0 gobject-2.0
WANTLIB += intl jansson m pthread seafile searpc sqlite3 ssl uuid
WANTLIB += ${COMPILER_LIBCXX}

MODULES =		devel/cmake x11/qt5
LIB_DEPENDS =		net/seafile/seafile \
			databases/sqlite3
RUN_DEPENDS = 		devel/desktop-file-utils \
			x11/gtk+3,-guic

NO_TEST =		Yes

post-configure:
	cd ${WRKSRC}/i18n/ && ${MODQT_LRELEASE} *.ts

.include <bsd.port.mk>
