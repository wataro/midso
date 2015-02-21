/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "Poco/Util/Application.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/AbstractConfiguration.h"
#include "Poco/AutoPtr.h"


using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;
using Poco::Util::AbstractConfiguration;
using Poco::Util::OptionCallback;
using Poco::AutoPtr;

/**
This sample demonstrates some of the features of the Util::Application class,
such as configuration file handling and command line arguments processing.

Try MidsoApp --help (on Unix platforms) or MidsoApp /help (elsewhere) for
more information.
*/
class MidsoApp: public Application {
 public:
    MidsoApp(): _helpRequested(false) {
    }

 protected:
    void initialize(std::shared_ptr<Application> self) {
        // load default configuration files, if present
        loadConfiguration();
        Application::initialize(*self);
        // add your own initialization code here
    }

    void uninitialize() {
        // add your own uninitialization code here
        Application::uninitialize();
    }

    void reinitialize(Application& self) {
        Application::reinitialize(self);
        // add your own reinitialization code here
    }

    void defineOptions(OptionSet& options) {
        Application::defineOptions(options);

        options.addOption(
            Option("help",
                   "h",
                   "display help information on command line arguments")
                .required(false)
                .repeatable(false)
                .callback(
                    OptionCallback<MidsoApp>(this, &MidsoApp::handleHelp)));

        options.addOption(
            Option("define", "D", "define a configuration property")
                .required(false)
                .repeatable(true)
                .argument("name=value")
                .callback(
                    OptionCallback<MidsoApp>(this, &MidsoApp::handleDefine)));

        options.addOption(
            Option("config-file", "f", "load configuration data from a file")
                .required(false)
                .repeatable(true)
                .argument("file")
                .callback(
                    OptionCallback<MidsoApp>(this, &MidsoApp::handleConfig)));

        options.addOption(
            Option("bind", "b", "bind option value to test.property")
                .required(false)
                .repeatable(false)
                .argument("value")
                .binding("test.property"));
    }

    void handleHelp(const std::string& name, const std::string& value) {
        _helpRequested = true;
        displayHelp();
        stopOptionsProcessing();
    }

    void handleDefine(const std::string& name, const std::string& value) {
        defineProperty(value);
    }

    void handleConfig(const std::string& name, const std::string& value) {
        loadConfiguration(value);
    }

    void displayHelp() {
        HelpFormatter helpFormatter(options());
        helpFormatter.setCommand(commandName());
        helpFormatter.setUsage("OPTIONS");
        helpFormatter.setHeader("A sample application that demonstrates"
        "some of the features of the Poco::Util::Application class.");
        helpFormatter.format(std::cout);
    }

    void defineProperty(const std::string& def) {
        std::string name;
        std::string value;
        std::string::size_type pos = def.find('=');
        if (pos != std::string::npos) {
            name.assign(def, 0, pos);
            value.assign(def, pos + 1, def.length() - pos);
        } else {
            name = def;
        }
        config().setString(name, value);
    }

    int main(const ArgVec& args) {
        if (!_helpRequested) {
            logger().information("Command line:");
            std::ostringstream ostr;
            for (ArgVec::const_iterator it = argv().begin();
                 it != argv().end();
                 ++it) {
                ostr << *it << ' ';
            }
            logger().information(ostr.str());
            logger().information("Arguments to main():");
            for (ArgVec::const_iterator it = args.begin();
                 it != args.end();
                 ++it) {
                logger().information(*it);
            }
            logger().information("Application properties:");
            printProperties("");
        }
        return Application::EXIT_OK;
    }

    void printProperties(const std::string& base) {
        typedef AbstractConfiguration::Keys AbstractConfKeys;
        AbstractConfiguration::Keys keys;
        config().keys(base, keys);
        if (keys.empty()) {
            if (config().hasProperty(base)) {
                std::string msg;
                msg.append(base);
                msg.append(" = ");
                msg.append(config().getString(base));
                logger().information(msg);
            }
        } else {
            for (AbstractConfKeys::const_iterator it = keys.begin();
                 it != keys.end();
                 ++it) {
                std::string fullKey = base;
                if (!fullKey.empty()) fullKey += '.';
                fullKey.append(*it);
                printProperties(fullKey);
            }
        }
    }

 private:
    bool _helpRequested;
};


POCO_APP_MAIN(MidsoApp)

