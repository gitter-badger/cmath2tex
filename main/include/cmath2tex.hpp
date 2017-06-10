/**
 * @file cmath2tex.hpp
 * @date 03.06.17
 * @author galarius
 * @copyright   Copyright © 2017 galarius. All rights reserved.
 * @brief Formla parser and converter from C language into LaTeX
 */

#ifndef cmath2tex_hpp
#define cmath2tex_hpp

#include "lexeme.hpp"

#include <string>
#include <vector>
#include <regex>

/**
 * @brief Formla parser and converter from C language into LaTeX.
 */
class CMath2Tex
{
public:
    /**
     * Tag styles
     */
    enum EQUATION_TAG_STYLE
    {
        DISPLAY,    ///< $$
        INLINE,     ///< $
        DOXYFILE    ///< /f$
    };
public:
    /**
     * @param[in] identified_regs regular expressions for formula parsing in format {<regex>, <group>}
     *
     * Example:
     * @code{.cpp}
     * 	std::vector<std::pair<std::string, std::string>> regs
     *   {
     *  	{ "[a-z]+", "variable" },
     *		{ R"!(\*|\+|\-|\/)!", "operator" },
     *		{ R"!(\(|\))!", "parenthesis" }
     *   };
     * @endcode
     */
    explicit CMath2Tex(const std::vector<std::pair<std::string, std::string>>& grouped_regs);
    
    ~CMath2Tex() = default;
    
    CMath2Tex(const CMath2Tex& other);
    CMath2Tex& operator=(const CMath2Tex& other);
    CMath2Tex(CMath2Tex &&other);
    CMath2Tex& operator=(CMath2Tex &&other);
    
public:
    /**
     * @brief Default regex, that contains C maths function library
     */
    static std::vector<std::pair<std::string, std::string>> default_regex();
    /**
     * @brief Convert C formula to LaTeX
     * @param[in] in text, that contains formula
     * @param[in] style tag style
     * @return converted formula
     * @see EQUATION_TAG_STYLE
     */
    std::string translate(const std::string& in, EQUATION_TAG_STYLE style = DOXYFILE);
    /**
     * @brief Get hit count for specified group
     */
    int group_hits(const std::string& group);
private:
    /**
     * @brief Analyze tokens and convert formulas to LaTeX format
     * @param tokens tokens extracted with lexical analyzer
     * @return conversion result
     */
    std::string translate(const std::vector<std::string>& tokens);
    /**
     * @brief match index from grouped_regs_
     * @param[in] it current match iterator
     * @return match index
     */
    size_t match_index(std::sregex_iterator it);
    /**
     * @brief Devide text in tokens
     * @param[in] in text, that contains formula
     * @return tokens
     */
    std::vector<std::string> lexical_analyzer(const std::string& in);
    /**
     * Open tag for LaTeX math equation
     * @param style tag style
     * @return tag in specified style
     */
    std::string eq_open_tag(EQUATION_TAG_STYLE style);
    /**
     * Close tag for LaTeX math equation
     * @param style tag style
     * @return tag in specified style
     */
    std::string eq_close_tag(EQUATION_TAG_STYLE style);
private:
    std::string regex_txt_; ///< @brief full regex expression as string
    /**
     * @brief Vector of regex expresions in form {<regex>, <group>}
     */
    std::vector<std::pair<std::string, std::string>> grouped_regs_;
    /**
     * @brief Statistics of each regex group hits
     */
    std::unordered_map<std::string, int>  grouped_hits_;
};
    
#endif /* cmath2tex_hpp */
