/*
 * $FU-Copyright$
 */

#ifndef ARACLIENTMOCK_H_
#define ARACLIENTMOCK_H_

#include "AbstractARAClient.h"
#include "AbstractClientMockBase.h"
#include "Packet.h"
#include "NetworkInterfaceMock.h"
#include "PacketTrap.h"
#include "RoutingTable.h"

#include <string>
#include <deque>

namespace ARA {

/**
 * A ARAClientMock implements the abstract ARA Client and holds references to
 * other mocks for testing the routing table, packet trap and network interfaces.
 */
class ARAClientMock: public AbstractARAClient, public AbstractClientMockBase {
public:
    ARAClientMock();

    void receivePacket(Packet* packet, NetworkInterface* interface);
    virtual void handleRouteFailure(Packet* packet, std::shared_ptr<Address> nextHop, NetworkInterface* interface);

    void deliverToSystem(const Packet* packet);
    void packetNotDeliverable(const Packet* packet);


    PacketTrap* getPacketTrap();
    RoutingTable* getRoutingTable();
    NetworkInterfaceMock* createNewNetworkInterfaceMock(const std::string localAddressName = "DEFAULT");
};

} /* namespace ARA */
#endif /* ARACLIENTMOCK_H_ */
