# $OpenBSD: Makefile,v 1.69 2017/09/16 22:56:41 jeremy Exp $

# Runtime failures on i386 in IO#pos and IO#rewind
ONLY_FOR_ARCHS = amd64

COMMENT =	pure-Java implementation of the Ruby language

V =		9.1.13.0
DISTNAME =	jruby-bin-${V}
PKGNAME =	jruby-${V}
CATEGORIES =	lang lang/ruby
DISTFILES =	${DISTNAME}.tar.gz \
		jnr-jffi-1.2.2-0-g4c196bb.tar.gz:0 \
		${JRUBY_LAUNCHER_GEM}:1

REVISION =	0

HOMEPAGE =	http://www.jruby.org/

MAINTAINER =	Jeremy Evans <jeremy@openbsd.org>

# EPLv1/GPLv2/LGPLv2.1/Ruby/MIT/BSD/Apache/CPL
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =	https://s3.amazonaws.com/jruby.org/downloads/${V}/
MASTER_SITES0 =	http://www.distfiles.nl/
MASTER_SITES1 =	${MASTER_SITE_RUBYGEMS}

MODULES =	java
MODJAVA_VER =	1.8+
MODJAVA_JRERUN = Yes
USE_GMAKE =	Yes

WANTLIB =	c m pthread ${COMPILER_LIBCXX}

BUILD_DEPENDS =	devel/apache-ant \
		shells/bash \
		${RUN_DEPENDS}
RUN_DEPENDS =	java/javaPathHelper

MAKE_ENV =	JAVA_HOME=${JAVA_HOME} MAKE=${MAKE_PROGRAM}

JRUBY_HOME =	${PREFIX}/jruby

WRKDIST =	${WRKDIR}/jruby-${V}
ANT_CMD =	${SETENV} ${MAKE_ENV} PATH=${JAVA_HOME}/bin:${PATH} \
			${LOCALBASE}/bin/ant
JFFI_HOME =	${WRKDIST}/jffi
JFFI_ARCH =	${MACHINE_ARCH:S/amd64/x86_64/}-OpenBSD
FFI_ARCH =	${JFFI_ARCH:L}
JRUBY_LAUNCHER_GEM = jruby-launcher-1.1.1-java.gem
SUBST_VARS =	JRUBY_HOME JFFI_ARCH FFI_ARCH RAKE_V RDOC_V JAVA_HOME

post-extract:
	mv ${WRKDIR}/jnr-jffi* ${JFFI_HOME}
	# Unpack the jruby-launcher gem, since it needs to be patched
	cd ${WRKSRC} && mkdir jruby-launcher \
		&& cd jruby-launcher && tar zxf ../../data.tar.gz \
		&& rm -f ../../data.tar.gz
	cp ${WRKSRC}/lib/ruby/gems/shared/gems/*/bin/* ${WRKSRC}/bin/

do-configure:
	${SUBST_CMD} ${WRKSRC}/jruby-launcher/jrubyexe.cpp \
		${WRKSRC}/jruby-launcher/unixlauncher.cpp
	cd ${WRKSRC}/jruby-launcher/ && ${SET_ENV} ${MAKE_ENV} \
		../bin/jruby extconf.rb
	perl -pi -e '$$. == 1 && s|^.*env j?ruby.*$$|\#!${LOCALBASE}/bin/jruby|;' \
                -e '$$. == 1 && s|^.*bin/j?ruby.*$$|\#!${LOCALBASE}/bin/jruby|;' \
                -e 'close ARGV if eof;' ${WRKSRC}/bin/!(*.*)

do-build:
	cd ${JFFI_HOME} && ${ANT_CMD} jar
	rm -rf ${WRKSRC}/lib/jni
	mkdir -p ${WRKSRC}/lib/jni/${JFFI_ARCH}
	cp ${JFFI_HOME}/build/jni/libjffi-1.2.so \
		${WRKSRC}/lib/jni/${JFFI_ARCH}
	cd ${WRKSRC}/lib/ruby/stdlib/ffi/platform && \
		rm -r !(${FFI_ARCH}|*.ffi)
	cd ${WRKSRC}/jruby-launcher/ && gmake && mv jruby ../bin

do-install:
	ln -s ${TRUEPREFIX}/jruby/bin/jruby ${PREFIX}/bin/jruby
	${INSTALL_DATA_DIR} ${JRUBY_HOME}
	${INSTALL_DATA_DIR} ${JRUBY_HOME}/bin
	for file in ast gem jgem jirb jirb_swing jruby rake rdoc ri testrb; \
	  do ${INSTALL_SCRIPT} ${WRKBUILD}/bin/$$file ${JRUBY_HOME}/bin/$$file; \
	done
	${INSTALL_DATA_DIR} ${JRUBY_HOME}/lib
	cd ${WRKBUILD}/lib && tar -cf - * | \
		tar -C ${JRUBY_HOME}/lib -xf -
	mkdir -p ${JRUBY_HOME}/lib/ruby/{1.8,1.9,2.0}/site_ruby
	find ${JRUBY_HOME}/lib -name '*.orig' -print0 | xargs -0r rm
	find ${JRUBY_HOME}/lib -name '*.beforesubst' -print0 | xargs -0r rm
	mv ${JRUBY_HOME}/lib/ruby/gems/{shared,1.8}
	ln -s 1.8 ${JRUBY_HOME}/lib/ruby/gems/shared
	chown -R ${SHAREOWN}:${SHAREGRP} ${JRUBY_HOME}/lib

# JRuby doesn't ship tests in the binary distribution
# Try running the database/ruby-sequel,jruby tests after an update
NO_TEST =	Yes

.include <bsd.port.mk>
