# $OpenBSD: Makefile,v 1.40 2017/07/26 22:45:16 sthen Exp $

COMMENT=	managing meta-data of audio formats
DISTNAME=	taglib-1.9.1
REVISION =	3
CATEGORIES=	audio devel

MASTER_SITES=	http://taglib.github.io/releases/

SHARED_LIBS +=	tag	11.0	# 1.9.1
SHARED_LIBS +=	tag_c	2.1	# 0.0.0

HOMEPAGE= 	http://taglib.github.io/

# LGPLv2.1 / MPLv1.1
PERMIT_PACKAGE_CDROM=	Yes

MODULES=	devel/cmake

WANTLIB=	${COMPILER_LIBCXX} m z

BUILD_DEPENDS=	devel/cppunit

CONFIGURE_ARGS=	-DCMAKE_POLICY_DEFAULT_CMP0022=OLD \
		-DBUILD_TESTS:BOOL=ON

pre-configure:
	${SUBST_CMD} ${WRKSRC}/cmake/modules/FindCppUnit.cmake

do-test:
	@ln -f -s ${WRKSRC}/tests/data ${WRKBUILD}/tests/data
	@cd ${WRKBUILD}/tests && ./test_runner

.include <bsd.port.mk>
