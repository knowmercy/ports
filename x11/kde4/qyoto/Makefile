# $OpenBSD: Makefile,v 1.16 2017/10/30 13:55:11 landry Exp $

CATEGORIES =	devel
COMMENT =	Qt4 bindings for .NET/Mono
DISTNAME =	qyoto-${MODKDE4_VERSION}
REVISION =	4

SHARED_LIBS =	qyoto			50.1 # 2.0
SHARED_LIBS +=	phonon-sharp		50.1
SHARED_LIBS +=	qscintilla-sharp	50.1
SHARED_LIBS +=	qtscript-sharp		50.1
SHARED_LIBS +=	qttest-sharp		50.1
SHARED_LIBS +=	qtuitools-sharp		50.1
SHARED_LIBS +=	qtwebkit-sharp		50.1

WANTLIB =  c m pthread
WANTLIB += ${COMPILER_LIBCXX}
WANTLIB += lib/qt4/QtDBus lib/qt4/QtGui lib/qt4/QtNetwork
WANTLIB += lib/qt4/QtScript lib/qt4/QtTest lib/qt4/QtWebKit
WANTLIB += lib/qt4/QtXml
WANTLIB += ${KDE4LIB}/smokebase ${KDE4LIB}/smokephonon ${KDE4LIB}/smokeqsci
WANTLIB += ${KDE4LIB}/smokeqtcore ${KDE4LIB}/smokeqtdbus
WANTLIB += ${KDE4LIB}/smokeqtgui ${KDE4LIB}/smokeqtnetwork
WANTLIB += ${KDE4LIB}/smokeqtopengl ${KDE4LIB}/smokeqtsql
WANTLIB += ${KDE4LIB}/smokeqtsvg ${KDE4LIB}/smokeqtxml
WANTLIB += ${KDE4LIB}/smokeqtscript ${KDE4LIB}/smokeqttest
WANTLIB += ${KDE4LIB}/smokeqtuitools ${KDE4LIB}/smokeqtwebkit
WANTLIB += qscintilla2_qt4

MODULES =	multimedia/phonon lang/mono
MODMONO_GMCS_COMPAT = Yes

MODKDE4_USE =

LIB_DEPENDS =	editors/qscintilla \
		${MODKDE4_DEP_DIR}/smokeqt

CONFIGURE_ARGS =	-DPHONON_INCLUDE_DIR:String=${LOCALBASE}/${MODKDE4_INCLUDE_DIR}

NO_TEST =	Yes

.include <bsd.port.mk>
