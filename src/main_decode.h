/*
 * Centaurean Density
 *
 * Copyright (c) 2013, Guillaume Voirin
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Centaurean nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * 18/10/13 23:50
 */

#ifndef DENSITY_MAIN_DECODE_H
#define DENSITY_MAIN_DECODE_H

#include "block_header.h"
#include "block_footer.h"
#include "main_header.h"
#include "main_footer.h"
#include "block_mode_marker.h"
#include "block_decode.h"
#include "kernel_chameleon_decode.h"
#include "density_api.h"
#include "block_footer.h"
#include "block_header.h"
#include "main_header.h"
#include "main_footer.h"
#include "block_mode_marker.h"
#include "block_encode.h"
#include "kernel_chameleon_encode.h"
#include "density_api.h"
#include "memory_location.h"

typedef enum {
    DENSITY_DECODE_STATE_READY = 0,
    DENSITY_DECODE_STATE_STALL_ON_OUTPUT_BUFFER,
    DENSITY_DECODE_STATE_STALL_ON_INPUT_BUFFER,
    DENSITY_DECODE_STATE_ERROR
} DENSITY_DECODE_STATE;

typedef enum {
    DENSITY_DECODE_PROCESS_READ_BLOCKS,
    DENSITY_DECODE_PROCESS_READ_FOOTER,
    DENSITY_DECODE_PROCESS_FINISHED
} DENSITY_DECODE_PROCESS;

#pragma pack(push)
#pragma pack(4)
typedef struct {
    DENSITY_DECODE_PROCESS process;

    uint_fast64_t totalRead;
    uint_fast64_t totalWritten;

    density_main_header header;
    density_main_footer footer;

    density_block_decode_state blockDecodeState;
} density_decode_state;
#pragma pack(pop)

DENSITY_DECODE_STATE density_decode_init(density_memory_teleport *, density_decode_state *);

DENSITY_DECODE_STATE density_decode_process(density_memory_teleport *, density_memory_location *, density_decode_state *, const density_bool);

DENSITY_DECODE_STATE density_decode_finish(density_memory_teleport *, density_decode_state *);

#endif