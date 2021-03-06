#pragma once
#ifndef SYDEVS_EXAMPLES_HELLO_COUNT_NODE_H_
#define SYDEVS_EXAMPLES_HELLO_COUNT_NODE_H_

#include <sydevs/systems/atomic_node.h>

namespace sydevs_examples {

using namespace sydevs;
using namespace sydevs::systems;


class hello_count_node : public atomic_node
{
public:
    // Constructor/Destructor:
    hello_count_node(const std::string& node_name, const node_context& external_context);
    virtual ~hello_count_node() = default;

    // Attributes:
    virtual scale time_precision() const { return micro; }

    // Ports:

protected:
    // State Variables:
    int64 count;

    // Event Handlers:
    virtual duration initialization_event();
    virtual duration unplanned_event(duration elapsed_dt);
    virtual duration planned_event(duration elapsed_dt);
    virtual void finalization_event(duration elapsed_dt);
};


inline hello_count_node::hello_count_node(const std::string& node_name, const node_context& external_context)
    : atomic_node(node_name, external_context)
{
}


inline duration hello_count_node::initialization_event()
{
    count = 0;
    return 0_s;
}


inline duration hello_count_node::unplanned_event(duration elapsed_dt)
{
    return duration();
}


inline duration hello_count_node::planned_event(duration elapsed_dt)
{
    ++count;
    print("Hello " + tostring(count));

    return 1_s;
}


inline void hello_count_node::finalization_event(duration elapsed_dt)
{
}


}  // namespace

#endif
