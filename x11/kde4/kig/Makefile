# $OpenBSD: Makefile,v 1.13 2017/07/27 11:57:49 sthen Exp $

COMMENT =	KDE geometric constructions explorer
DISTNAME =	kig-${MODKDE4_VERSION}
REVISION =	2

WANTLIB =  c m pthread ${MODPY_WANTLIB}
WANTLIB += ${COMPILER_LIBCXX}
WANTLIB += lib/qt4/QtDBus lib/qt4/QtGui lib/qt4/QtNetwork
WANTLIB += lib/qt4/QtSvg lib/qt4/QtXml
WANTLIB += ${KDE4LIB}/kcmutils ${KDE4LIB}/kdeui ${KDE4LIB}/kemoticons
WANTLIB += ${KDE4LIB}/kidletime ${KDE4LIB}/kio ${KDE4LIB}/kparts
WANTLIB += ${KDE4LIB}/kprintutils ${KDE4LIB}/ktexteditor ${KDE4LIB}/kutils
WANTLIB += ${KDE4LIB}/nepomuk ${KDE4LIB}/nepomukutils
WANTLIB += boost_python-mt soprano

MODULES =	lang/python

LIB_DEPENDS =	devel/boost
RUN_DEPENDS =	devel/desktop-file-utils \
		x11/gtk+3,-guic

post-patch:
	${SUBST_CMD} ${WRKSRC}/pykig/pykig.py

.include <bsd.port.mk>
