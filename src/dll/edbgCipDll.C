//IBM_PROLOG_BEGIN_TAG
/*
 * eCMD for pdbg Project
 *
 * Copyright 2017,2018 IBM International Business Machines Corp.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 	http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
//IBM_PROLOG_END_TAG

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#include <inttypes.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

// Headers from eCMD
#include <ecmdDllCapi.H>
#include <ecmdStructs.H>
#include <ecmdReturnCodes.H>
#include <ecmdDataBuffer.H>
#include <ecmdSharedUtils.H>

// Extension headers
#include <cipDllCapi.H>
#include <cipStructs.H>

// Headers from pdbg
extern "C" {
#include <libpdbg.h>
}

// Headers from ecmd-pdbg
#include <edbgCommon.H>
#include <edbgOutput.H>
#include <p9_edbgCipDllInstrCtrl.H>
#include <p10_edbgCipDllInstrCtrl.H>

/* ################################################################# */
/* Base Functions - Base Functions - Base Functions - Base Functions */
/* ################################################################# */
uint32_t dllCipInitExtensionInPlugin() {
  /* Nothing for us to do to init an extention */
  return 0;
}

uint32_t dllCipGetSysInfo(cipSysInfo_t & o_sysInfo) {
  return ECMD_FUNCTION_NOT_SUPPORTED;
}

#ifndef CIP_REMOVE_MEMORY_FUNCTIONS
/* ######################################################################### */
/* Memory Functions - Memory Functions - Memory Functions - Memory Functions */
/* ######################################################################### */
uint32_t dllCipGetMemProc(const ecmdChipTarget & i_target, uint64_t i_address, uint32_t i_bytes, ecmdDataBuffer & o_memoryData, ecmdDataBuffer & o_memoryTags, ecmdDataBuffer & o_memoryEcc, ecmdDataBuffer & o_memoryEccError) {
  return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllCipPutMemProc(const ecmdChipTarget & i_target, uint64_t i_address, uint32_t i_bytes, const ecmdDataBuffer & i_memoryData, const ecmdDataBuffer & i_memoryTags, const ecmdDataBuffer & i_memoryErrorInject) {
  return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllCipGetMemMemCtrl(const ecmdChipTarget & i_target, uint64_t i_address, uint32_t i_bytes, ecmdDataBuffer & o_memoryData, ecmdDataBuffer & o_memoryTags, ecmdDataBuffer & o_memoryEcc, ecmdDataBuffer & o_memoryEccError, ecmdDataBuffer & o_memorySpareBits) {
  return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllCipPutMemMemCtrl(const ecmdChipTarget & i_target, uint64_t i_address, uint32_t i_bytes, const ecmdDataBuffer & i_memoryData, const ecmdDataBuffer & i_memoryTags, const ecmdDataBuffer & i_memoryEcc, const ecmdDataBuffer & i_memorySpareBits, const ecmdDataBuffer & i_memoryErrorInject) {
  return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllCipGetMemPba(const ecmdChipTarget & i_target, uint64_t i_address, uint32_t i_bytes, ecmdDataBuffer & o_data) {
  return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllCipPutMemPba(const ecmdChipTarget & i_target, uint64_t i_address, uint32_t i_bytes, const ecmdDataBuffer & i_data, uint32_t i_mode) {
  return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllCipGetMemProcVariousAddrType(const ecmdChipTarget & i_target, ecmdDataBuffer i_address, uint32_t i_bytes, cipXlateVariables i_xlateVars, ecmdDataBuffer & o_memoryData, ecmdDataBuffer & o_memoryTags, ecmdDataBuffer & o_memoryEcc, ecmdDataBuffer & o_memoryEccError, ecmdDataBuffer & o_realAddress) {
  return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllCipPutMemProcVariousAddrType(const ecmdChipTarget & i_target, ecmdDataBuffer i_address, uint32_t i_bytes, cipXlateVariables i_xlateVars, const ecmdDataBuffer & i_memoryData, ecmdDataBuffer & io_memoryTags, ecmdDataBuffer & o_realAddress) {
  return ECMD_FUNCTION_NOT_SUPPORTED;
}
#endif // CIP_REMOVE_MEMORY_FUNCTIONS

#ifndef CIP_REMOVE_INSTRUCTION_FUNCTIONS
/* ################################################################# */
/* Proc Functions - Proc Functions - Proc Functions - Proc Functions */
/* ################################################################# */
uint32_t dllCipStartInstructions(const ecmdChipTarget & i_target, uint32_t i_thread) {
    
    uint32_t rc = ECMD_SUCCESS;
    
    if (pdbg_get_proc() == PDBG_PROC_P10) {
      rc = p10_dllCipStartInstructions(i_target, i_thread);
    } else {
      return ECMD_FUNCTION_NOT_SUPPORTED;
    }
    return rc;
}

uint32_t dllCipStartAllInstructions() {
    
    uint32_t rc = ECMD_SUCCESS;
    
    if (pdbg_get_proc() == PDBG_PROC_P9) {
      rc = p9_dllCipStartAllInstructions();
    } else if (pdbg_get_proc() == PDBG_PROC_P10) {
      rc = p10_dllCipStartAllInstructions();
    } else {
      return ECMD_FUNCTION_NOT_SUPPORTED;
    }
    return rc;
}

uint32_t dllCipStartInstructionsSreset(const ecmdChipTarget & i_target, uint32_t i_thread) {
    return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllCipStartAllInstructionsSreset() {
    return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllCipStopInstructions(const ecmdChipTarget & i_target, uint32_t i_thread) {
    
    uint32_t rc = ECMD_SUCCESS;
    
    if (pdbg_get_proc() == PDBG_PROC_P10) {
      rc = p10_dllCipStopInstructions(i_target, i_thread);
    } else {
      return ECMD_FUNCTION_NOT_SUPPORTED;
    }
    return rc;
}

uint32_t dllCipStopAllInstructions() {
    
    uint32_t rc = ECMD_SUCCESS;
    
    if (pdbg_get_proc() == PDBG_PROC_P9) {
      rc = p9_dllCipStopAllInstructions();
    } else if (pdbg_get_proc() == PDBG_PROC_P10) {
      rc = p10_dllCipStopAllInstructions();
    } else {
      return ECMD_FUNCTION_NOT_SUPPORTED;
    }
    return rc;
}

uint32_t dllCipStepInstructions(const ecmdChipTarget & i_target, uint32_t i_steps, uint32_t i_thread) {
    return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllCipSpecialWakeup(const ecmdChipTarget & i_target, bool i_enable, uint32_t i_mode) {
    
    uint32_t rc = ECMD_SUCCESS;

    if (pdbg_get_proc() == PDBG_PROC_P10) {
      rc = p10_dllCipSpecialWakeup(i_target, i_enable, i_mode);
    } else {
      return ECMD_FUNCTION_NOT_SUPPORTED;
    }
    return rc;
}

#endif // CIP_REMOVE_INSTRUCTION_FUNCTIONS
