/**
 *  Copyright (C) 2021 FISCO BCOS.
 *  SPDX-License-Identifier: Apache-2.0
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 * @brief interface for RPC
 * @file Rpc.h
 * @author: octopus
 * @date 2021-07-15
 */

#pragma once
#include <bcos-framework/interfaces/rpc/RPCInterface.h>
#include <bcos-rpc/rpc/Common.h>
#include <bcos-rpc/rpc/http/HttpServer.h>

namespace bcos
{
namespace rpc
{
class Rpc : public RPCInterface, public std::enable_shared_from_this<Rpc>
{
public:
    using Ptr = std::shared_ptr<Rpc>;

    Rpc() = default;
    virtual ~Rpc() { stop(); }

public:
    virtual void start() override;
    virtual void stop() override;

public:
    /**
     * @brief: notify blockNumber to rpc
     * @param _blockNumber: blockNumber
     * @param _callback: resp callback
     * @return void
     */
    virtual void asyncNotifyBlockNumber(bcos::protocol::BlockNumber _blockNumber,
        std::function<void(Error::Ptr)> _callback) override;

public:
    bcos::http::HttpServer::Ptr httpServer() const { return m_httpServer; }
    void setHttpServer(bcos::http::HttpServer::Ptr _httpServer) { m_httpServer = _httpServer; }

private:
    bcos::http::HttpServer::Ptr m_httpServer;
};

}  // namespace rpc
}  // namespace bcos