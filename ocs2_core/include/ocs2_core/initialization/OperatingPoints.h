/******************************************************************************
Copyright (c) 2020, Farbod Farshidian. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the copyright holder nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

#pragma once

#include <ocs2_core/initialization/SystemOperatingTrajectoriesBase.h>

namespace ocs2 {

/**
 * This class initializes the DDP-based algorithms based on operating trajectories or single points
 * for state and input.
 */
class OperatingPoints : public SystemOperatingTrajectoriesBase {
 public:
  /**
   * Constructor
   *
   * @param [in] stateOperatingPoint: The state operating point.
   * @param [in] inputOperatingPoint: The input operating point.
   */
  OperatingPoints(const vector_t& stateOperatingPoint, const vector_t& inputOperatingPoint);

  /**
   * Constructor
   *
   * @param [in] timeTrajectory: The time stamp of the operating trajectories.
   * @param [in] stateTrajectory: The state operating trajectory.
   * @param [in] inputTrajectory: The input operating trajectory.
   */
  OperatingPoints(scalar_array_t timeTrajectory, const vector_array_t& stateTrajectory, const vector_array_t& inputTrajectory);

  /**
   * Destructor
   */
  ~OperatingPoints() override = default;

  OperatingPoints* clone() const override;

  void getSystemOperatingTrajectories(const vector_t& initialState, scalar_t startTime, scalar_t finalTime, scalar_array_t& timeTrajectory,
                                      vector_array_t& stateTrajectory, vector_array_t& inputTrajectory, bool concatOutput = false) override;

 private:
  /**
   * Gets the Operating Trajectories of the system in time interval [startTime, finalTime] where there is no intermediate switches.
   *
   * @param [in] startTime: Initial time.
   * @param [in] finalTime: Final time.
   * @param [out] timeTrajectory: Output time stamp trajectory.
   * @param [out] stateTrajectory: Output state trajectory.
   * @param [out] inputTrajectory: Output control input trajectory.
   */
  void getSystemOperatingTrajectoriesImpl(scalar_t startTime, scalar_t finalTime, scalar_array_t& timeTrajectory,
                                          vector_array_t& stateTrajectory, vector_array_t& inputTrajectory) const;

  scalar_array_t timeTrajectory_;
  vector_array_t stateTrajectory_;
  vector_array_t inputTrajectory_;
};

}  // namespace ocs2
