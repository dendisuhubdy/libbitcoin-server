/**
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin-server.
 *
 * libbitcoin-server is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_SERVER_BLOCKCHAIN_HPP
#define LIBBITCOIN_SERVER_BLOCKCHAIN_HPP

#include <bitcoin/blockchain.hpp>
#include <bitcoin/server/define.hpp>
#include <bitcoin/server/messaging/incoming_message.hpp>
#include <bitcoin/server/messaging/outgoing_message.hpp>

namespace libbitcoin {
namespace server {

class server_node;

// TODO: convert to class static.

void BCS_API address_fetch_history2(server_node& node,
    const incoming_message& request, send_handler handler);

void BCS_API blockchain_fetch_history(server_node& node,
    const incoming_message& request, send_handler handler);

void BCS_API blockchain_fetch_transaction(server_node& node,
    const incoming_message& request, send_handler handler);

void BCS_API blockchain_fetch_last_height(server_node& node,
    const incoming_message& request, send_handler handler);

void BCS_API blockchain_fetch_block_header(server_node& node,
    const incoming_message& request, send_handler handler);

void BCS_API blockchain_fetch_block_transaction_hashes(server_node& node,
    const incoming_message& request, send_handler handler);

void BCS_API blockchain_fetch_transaction_index(server_node& node,
    const incoming_message& request, send_handler handler);

void BCS_API blockchain_fetch_spend(server_node& node,
    const incoming_message& request, send_handler handler);

void BCS_API blockchain_fetch_block_height(server_node& node,
    const incoming_message& request, send_handler handler);

void BCS_API blockchain_fetch_stealth(server_node& node,
    const incoming_message& request, send_handler handler);

// TODO: private

void last_height_fetched(const code& ec, size_t last_height,
    const incoming_message& request, send_handler handler);

void fetch_block_header_by_hash(server_node& node,
    const incoming_message& request, send_handler handler);

void fetch_block_header_by_height(server_node& node,
    const incoming_message& request, send_handler handler);

void block_header_fetched(const code& ec, const chain::header& block,
    const incoming_message& request, send_handler handler);

void fetch_block_transaction_hashes_by_hash(server_node& node,
    const incoming_message& request, send_handler handler);

void fetch_block_transaction_hashes_by_height(server_node& node,
    const incoming_message& request, send_handler handler);

void block_transaction_hashes_fetched(const code& ec,
    const hash_list& hashes, const incoming_message& request,
    send_handler handler);

void transaction_index_fetched(const code& ec, size_t block_height,
    size_t index, const incoming_message& request, send_handler handler);

void spend_fetched(const code& ec, const chain::input_point& inpoint,
    const incoming_message& request, send_handler handler);

void block_height_fetched(const code& ec, size_t block_height,
    const incoming_message& request, send_handler handler);

void stealth_fetched(const code& ec,
    const blockchain::block_chain::stealth& stealth_results,
    const incoming_message& request, send_handler handler);

} // namespace server
} // namespace libbitcoin

#endif

