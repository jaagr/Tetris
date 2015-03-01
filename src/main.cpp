#include <boost/msm/back/state_machine.hpp>
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/front/euml/euml.hpp>

#include <boost/di.hpp>
#include <boost/iterator/iterator_concepts.hpp>

namespace msm   = boost::msm;
namespace front = boost::msm::front;
namespace euml  = boost::msm::front::euml;
namespace di    = boost::di;

struct idata {
    virtual int get_value() = 0;
    virtual void increase_value() = 0;
};

struct data : idata{
    int value;
    
    data(int value):value(value) {}
    
    int get_value() {
        return value;
    }
    
    void increase_value() {
        ++value;        
    }
};

struct event : euml::euml_event<event> { };

class guard : public euml::euml_action<guard> {
public:
    guard() { } // for euml

    explicit guard(std::shared_ptr<idata> data_)
        : data_(data_)
    { }

    bool operator()(const event&) const {
        return data_->get_value() != 0;
    }

private:
    std::shared_ptr<idata> data_;
};

class action : public euml::euml_action<action> {
public:
    action() { } // for euml

    explicit action(std::shared_ptr<idata> data_)
        : data_(data_)
    { }

    void operator()(const event&) {
        data_->increase_value();
    }

private:
    std::shared_ptr<idata> data_;
};

class state_machine_ : public front::state_machine_def<state_machine_> {
    struct state1 : front::state<>, euml::euml_state<state1> { };
    struct state2 : front::state<>, euml::euml_state<state2> { };

public:
    using initial_state = state1;

    BOOST_MSM_EUML_DECLARE_TRANSITION_TABLE((
        state1() + event() [guard()] / action() == state2()
    ), transition_table)
};

using state_machine = msm::back::state_machine<
    state_machine_
  , msm::back::use_dependency_injection
>;

int main() {
    auto sm = di::make_injector(di::bind<idata, data>).create<state_machine>();
    sm.process_event(event());

    return 0;
}