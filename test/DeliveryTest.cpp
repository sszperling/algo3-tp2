#include <gtest/gtest.h>
#include "../src/graph.h"
#include "../src/delivery.h"

class DeliveryTest : public ::testing::Test {
protected:
    edge* edges;
    struct input {
        int n;
        int m;
        int origin;
        int destiny;
        int k;
        int countPremium;
        std::vector<edge> vEdges;
    };

    virtual void SetUp() {
        edges = NULL;
    }

    virtual void TearDown() {
        if(edges != NULL) {
            delete[] edges;
        }
    }
};

TEST_F(DeliveryTest, fewEdges) {
    input in;
    in.n = 4;
    in.m = 6;
    in.origin = 2;
    in.destiny = 0;
    in.k = 1;
    in.countPremium = 0;
    addEdgeToPremiumGraph(2, 0, 0, 20, in.k, in.n, &in.vEdges);
    addEdgeToPremiumGraph(1, 0, 1, 6, in.k, in.n, &in.vEdges);
    addEdgeToPremiumGraph(1, 3, 0, 8, in.k, in.n, &in.vEdges);
    addEdgeToPremiumGraph(0, 3, 0, 7, in.k, in.n, &in.vEdges);
    addEdgeToPremiumGraph(2, 3, 1, 2, in.k, in.n, &in.vEdges);
    addEdgeToPremiumGraph(2, 1, 1, 3, in.k, in.n, &in.vEdges);
    in.countPremium = 3;

    ASSERT_EQ(optimumDelivery(in.origin, in.destiny, in.n, in.countPremium, in.m, in.k, &(in.vEdges[0])), 9);


}