//${WS}/hometec/bundles/hometec/src/HelloWorldActivator.cc
#include <memory>
#include <iostream>

#include <celix_api.h>

namespace /*anon*/ {

    class BundleActivator {
    public:
        BundleActivator(std::shared_ptr<celix::dm::DependencyManager> _mng) : mng{_mng} {
            std::cout << "Hello world from C++ bundle with id " << bndId() << std::endl;
        }
        ~BundleActivator() {
            std::cout << "Goodbye world from C++ bundle with id " << bndId() << std::endl;
        }
    private:
        long bndId() const {
            return celix_bundle_getId(celix_bundleContext_getBundle(mng->bundleContext()));
        }

        std::shared_ptr<celix::dm::DependencyManager> mng;
    };

}

CELIX_GEN_CXX_BUNDLE_ACTIVATOR(BundleActivator)