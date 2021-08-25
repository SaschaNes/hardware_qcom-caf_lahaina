/* Copyright (c) 2020, The Linux Foundataion. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above
*       copyright notice, this list of conditions and the following
*       disclaimer in the documentation and/or other materials provided
*       with the distribution.
*     * Neither the name of The Linux Foundation nor the names of its
*       contributors may be used to endorse or promote products derived
*       from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
* ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
* IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

#ifndef __PANEL_FEATURE_FACTORY_INTF_H__
#define __PANEL_FEATURE_FACTORY_INTF_H__

#include <memory>
#include <string>

#include "spr_intf.h"
#include "panel_feature_property_intf.h"
#include "rc_intf.h"

namespace sdm {

struct SPRInputConfig {
  std::string panel_name = {};
  uint32_t panel_xres = 0;
  uint32_t panel_yres = 0;
};

class PanelFeatureFactoryIntf {
 public:
  virtual ~PanelFeatureFactoryIntf() {}

  virtual std::shared_ptr<SPRIntf>
    CreateSPRIntf(const SPRInputConfig &input_cfg, PanelFeaturePropertyIntf *prop_intf) = 0;
  virtual std::unique_ptr<RCIntf> CreateRCIntf(const RCInputConfig &input_cfg,
                                               PanelFeaturePropertyIntf *prop_intf) = 0;
};

extern "C" PanelFeatureFactoryIntf *GetPanelFeatureFactoryIntf();

}  // namespace sdm

#endif  // __PANEL_FEATURE_FACTORY_INTF_H__
