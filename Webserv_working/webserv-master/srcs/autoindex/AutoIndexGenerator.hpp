/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AutoIndexGenerator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:27:32 by user42            #+#    #+#             */
/*   Updated: 2021/03/25 14:23:06 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_INDEX_GENERATOR_HPP

# define AUTO_INDEX_GENERATOR_HPP

# include "webserv.hpp"


class AutoIndexGenerator {
    public:
        AutoIndexGenerator(void);
        AutoIndexGenerator(AutoIndexGenerator const &src);
        virtual ~AutoIndexGenerator(void);

        AutoIndexGenerator   &operator=(AutoIndexGenerator const &src);

        static std::string  getPage(const char *path, std::string const &host, int port);
    private:
        static std::string  getLink(std::string const &dirEntry, std::string const &dirName, std::string const &host, int port);

};

#endif
