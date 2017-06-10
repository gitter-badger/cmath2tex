/**
* @file detector.hpp
* @date 03.06.17
* @author galarius
* @copyright Copyright © 2017 galarius. All rights reserved.
* @brief Detects math equations in source code
*/

#ifndef detector_hpp
#define detector_hpp

#include "cmath2tex.hpp"
#include <memory>

/**
 * @class Detector
 * @brief Detects math equations in source code
 */
class Detector
{
public:
    /**
     * @param[in] cmath2tex CMath2Tex instance to perform conversion from C to TeX
     */
    Detector(std::shared_ptr<CMath2Tex> cmath2tex);
    ~Detector() = default;
    
    /**
     * @brief Set filter options
     * @param[in] min_op_count min operation count
     * @param[in] min_fn_count min function count
     */
    void set_filter(int min_op_count, int min_fn_count);
public:
    /**
     * @brief Parse file stream with C code to detect convertable formulas and
     * write them to output stream
     * @param[in] in input stream
     * @param[in] out output stream
     */
    void perform(std::ifstream& in, std::ofstream& out);
private:
    /**
     * @brief Process detected formula, apply filter, write to stream
     * @param[in] formula detected formula
     * @param[in] stream  output stream
     */
    void process(const std::string& formula, std::ofstream& stream);
private:
    int min_op_count_;              ///< @brief min operation count
    int min_fn_count_;              ///< @brief min function count
    std::shared_ptr<CMath2Tex> cmath2tex_;    ///< @brief CMath2Tex instance
};

#endif /* detector_hpp */
