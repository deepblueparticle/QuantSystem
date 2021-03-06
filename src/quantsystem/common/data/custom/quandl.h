/*
 * \copyright Copyright 2015 All Rights Reserved.
 * \license @{
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @}
 */


#ifndef QUANTSYSTEM_COMMON_DATA_CUSTOM_H_
#define QUANTSYSTEM_COMMON_DATA_CUSTOM_H_

#include <string>
using std::string;
#include <vector>
using std::vector;

#include "quantsystem/common/data/dynamic_data.h"
#include "quantsystem/common/global.h"
#include "quantsystem/common/strings/stringpiece.h"
#include "quantsystem/common/time/date_time.h"


namespace quantsystem {
namespace data {
namespace custom {
/**
 * Quandl Data Class
 * @ingroup CommonBaseData
 *
 * Quandl Data Type - Import generic data from quandl,
 * without needing to define Reader methods. 
 * This reads the headers of the data imported,
 * and dynamically creates properties for the imported data.
 */
class Quandl : public DynamicData {
 public:
  /**
   * Standard constructor.
   */
  Quandl();

  /**
   * Standard destructor.
   */
  virtual ~Quandl();
  /**
   * Generic Reader Implementation for Quandl Data.
   *
   * @param config Subscription config.
   * @param line CSV line of data from the source.
   * @param date Date of the requested line.
   * @param data_feed Type of datafeed - a live or backtest feed.
   * @return Instance of BaseData object generated by this line of the CSV.
   */
  virtual BaseData* Reader(const SubscriptionDataConfig& config,
                           const StringPiece& line, const DateTime& date,
                           DataFeedEndpoint::Enum data_feed);

  /**
   * Quandl Source Locator.
   *
   * Using the Quandl V1 API automatically set the URL for the dataset.
   * More: https://www.quandl.com/help/api.
   *
   * @param config Subscription config.
   * @param date Date of the data file looked for.
   * @param data_feed Type of datafeed.
   * @return API URL for Quandl.
   */
  virtual string GetSource(const SubscriptionDataConfig& config,
                           const DateTime& date,
                           DataFeedEndpoint::Enum data_feed);

 private:
  bool is_initialized_;
  typedef vector<string> PropertyList;
  PropertyList property_names_;
};

}  // namespace custom
}  // namespace data
}  // namespace quantsystem

#endif  // QUANTSYSTEM_COMMON_DATA_CUSTOM_H_
