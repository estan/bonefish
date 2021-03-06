/**
 *  Copyright (C) 2015 Topology LP
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef BONEFISH_BROKER_WAMP_BROKER_TOPIC_HPP
#define BONEFISH_BROKER_WAMP_BROKER_TOPIC_HPP

#include <bonefish/session/wamp_session.hpp>

#include <unordered_set>

namespace bonefish {

class wamp_broker_topic
{
public:
    wamp_broker_topic();
    wamp_broker_topic(const std::string& topic);
    ~wamp_broker_topic();

    bool add_session(const std::shared_ptr<wamp_session>& session);
    bool remove_session(const std::shared_ptr<wamp_session>& session);
    const std::string& get_topic() const;
    const std::unordered_set<std::shared_ptr<wamp_session>>& get_sessions();

private:
    const std::string m_topic;
    std::unordered_set<std::shared_ptr<wamp_session>> m_sessions;
};

inline wamp_broker_topic::wamp_broker_topic()
    : m_topic()
    , m_sessions()
{
}

inline wamp_broker_topic::wamp_broker_topic(const std::string& topic)
    : m_topic(topic)
    , m_sessions()
{
}

inline wamp_broker_topic::~wamp_broker_topic()
{
}

inline bool wamp_broker_topic::add_session(const std::shared_ptr<wamp_session>& session)
{
    auto result = m_sessions.insert(session);
    return result.second;
}

inline bool wamp_broker_topic::remove_session(const std::shared_ptr<wamp_session>& session)
{
    return m_sessions.erase(session) != 0;
}

inline const std::string& wamp_broker_topic::get_topic() const
{
    return m_topic;
}

inline const std::unordered_set<std::shared_ptr<wamp_session>>& wamp_broker_topic::get_sessions()
{
    return m_sessions;
}

} // namespace bonefish

#endif // BONEFISH_BROKER_WAMP_BROKER_TOPIC_HPP
