#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=a
DEBUGGABLE_SUFFIX=a
FINAL_IMAGE=${DISTDIR}/PIC24FJ256GA702_lib.X.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=a
DEBUGGABLE_SUFFIX=a
FINAL_IMAGE=${DISTDIR}/PIC24FJ256GA702_lib.X.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=GPIO.c PIC24FJ256GA702_lib.c peripherals_interrupts.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/GPIO.o ${OBJECTDIR}/PIC24FJ256GA702_lib.o ${OBJECTDIR}/peripherals_interrupts.o
POSSIBLE_DEPFILES=${OBJECTDIR}/GPIO.o.d ${OBJECTDIR}/PIC24FJ256GA702_lib.o.d ${OBJECTDIR}/peripherals_interrupts.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/GPIO.o ${OBJECTDIR}/PIC24FJ256GA702_lib.o ${OBJECTDIR}/peripherals_interrupts.o

# Source Files
SOURCEFILES=GPIO.c PIC24FJ256GA702_lib.c peripherals_interrupts.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/PIC24FJ256GA702_lib.X.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ256GA702
MP_LINKER_FILE_OPTION=,--script=p24FJ256GA702.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/GPIO.o: GPIO.c  .generated_files/flags/default/adde730fffccaa2a5bd3eb9a620c2e2fe219351c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPIO.o.d 
	@${RM} ${OBJECTDIR}/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPIO.c  -o ${OBJECTDIR}/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPIO.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/PIC24FJ256GA702_lib.o: PIC24FJ256GA702_lib.c  .generated_files/flags/default/178a4a7f09d3cff2a2c84c6165660c28ca4390a5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PIC24FJ256GA702_lib.o.d 
	@${RM} ${OBJECTDIR}/PIC24FJ256GA702_lib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PIC24FJ256GA702_lib.c  -o ${OBJECTDIR}/PIC24FJ256GA702_lib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PIC24FJ256GA702_lib.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/peripherals_interrupts.o: peripherals_interrupts.c  .generated_files/flags/default/3001299a4c860a8dc54ca89619f2f76cb6e35b90 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/peripherals_interrupts.o.d 
	@${RM} ${OBJECTDIR}/peripherals_interrupts.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripherals_interrupts.c  -o ${OBJECTDIR}/peripherals_interrupts.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripherals_interrupts.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/GPIO.o: GPIO.c  .generated_files/flags/default/30bf4b03284fcc5919b449aeced3fa3fa29dd3f7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPIO.o.d 
	@${RM} ${OBJECTDIR}/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPIO.c  -o ${OBJECTDIR}/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPIO.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/PIC24FJ256GA702_lib.o: PIC24FJ256GA702_lib.c  .generated_files/flags/default/67857d428ed6a4e4243b3f17780ed43a2a788875 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PIC24FJ256GA702_lib.o.d 
	@${RM} ${OBJECTDIR}/PIC24FJ256GA702_lib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PIC24FJ256GA702_lib.c  -o ${OBJECTDIR}/PIC24FJ256GA702_lib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PIC24FJ256GA702_lib.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/peripherals_interrupts.o: peripherals_interrupts.c  .generated_files/flags/default/a8503df5e7c7ed124eccc4316f68be2814c30046 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/peripherals_interrupts.o.d 
	@${RM} ${OBJECTDIR}/peripherals_interrupts.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripherals_interrupts.c  -o ${OBJECTDIR}/peripherals_interrupts.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripherals_interrupts.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: archive
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/PIC24FJ256GA702_lib.X.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	@${RM} ${DISTDIR}/PIC24FJ256GA702_lib.X.${OUTPUT_SUFFIX} 
	${MP_AR} $(MP_EXTRA_AR_PRE)  -omf=elf -r ${DISTDIR}/PIC24FJ256GA702_lib.X.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}       -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/PIC24FJ256GA702_lib.X.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	@${RM} ${DISTDIR}/PIC24FJ256GA702_lib.X.${OUTPUT_SUFFIX} 
	${MP_AR} $(MP_EXTRA_AR_PRE)  -omf=elf -r ${DISTDIR}/PIC24FJ256GA702_lib.X.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}       -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
