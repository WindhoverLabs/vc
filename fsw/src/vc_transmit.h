/*==============================================================================
Copyright (c) 2017, Windhover Labs
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of CmdIn nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY VCPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, VCEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef VC_TRANSMIT_H
#define VC_TRANSMIT_H

#include "vc_config.h" /* move to platform_cfg */

typedef enum
{
    VC_CHANNEL_UNUSED       = 0,
    VC_CHANNEL_DISABLED     = 1,
    VC_CHANNEL_ENABLED      = 2
} VC_ChannelMode_t;


/**
 * Transmit struct handle for user defined source and/or destination
 * configuration information and initialized resource reference.
 */
typedef struct
{
    VC_ChannelMode_t    Mode;
    uint8               ChannelID;
    uint16              DestPort;
    uint16              MyPort;
    char                DestIP[INET_ADDRSTRLEN];
    char                MyIP[INET_ADDRSTRLEN];
    int                 SocketFd;
} VC_Transmit_Handle_t;


typedef struct
{
    VC_Transmit_Handle_t Channel[VC_MAX_OUTPUT_CHANNELS];
} VC_AppCustomData_t;


/**
 * @brief Initialize a configured resource.
 * @return true if successful, otherwise false
 */
boolean VC_Transmit_Init(void);


/**
 * @brief Uninitialize a previously initialized resource.
 * @return true if successful, otherwise false
 */
boolean VC_Transmit_Uninit(void);


/**
 * @brief Transmit data using a previously initialized handle.
 * @param buf points to a buffer containing the data to be sent.
 * @param len specifies the size of the data in bytes.
 * @return On success, returns the number of bytes sent. On error, -1 is
 * returned.
 */
int32 VC_SendData(uint32 ChannelID, const char* Buffer, uint32 Size);

#endif