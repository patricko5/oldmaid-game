#include "gtest/gtest.h"
#include "OldMaidUI.h"
#include "Card.h"
#include "Player.h"

TEST(TestOldMaidUI, RequestCardTest) {
    OldMaidUI ui;
    Player player("Alice");
    std::list<Card*> hand = {new Card(Card::HEART, Card::ACE), new Card(Card::SPADE, Card::TWO)};

    std::istringstream iss("1\n"); 
    std::cin.rdbuf(iss.rdbuf());

    unsigned int choice = ui.requestCard(&player, &hand);
    EXPECT_EQ(choice, 0); 

    for (auto card : hand) {
        delete card;
    }
}

TEST(TestOldMaidUI, PlayFailedTest) {
    OldMaidUI ui;
    testing::internal::CaptureStdout();
    ui.playFailed();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Play failed. No matching card found.\n");
}

TEST(TestOldMaidUI, PlaySucceededTest) {
    OldMaidUI ui;
    testing::internal::CaptureStdout();
    ui.playSucceeded();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Play succeeded! A matching card was found.\n");
}
TEST(TestOldMaidUI, ShowGameOutcomeTest) {
    OldMaidUI ui;
    Player player1("Alice");
    Player player2("Bob");

    Card* aliceCard = new Card(Card::HEART, Card::ACE); 
    player1.addCard(aliceCard); 

    std::vector<Player*> players = {&player1, &player2};
    testing::internal::CaptureStdout();
    ui.showGameOutcome(players);
    std::string output = testing::internal::GetCapturedStdout();
    std::string expectedOutput = "-------------------------------------------------------\nGame Over.\nAlice is left with the Old Maid and loses the game!\nCongratulations Bob, you successfully avoided the Old Maid.\n-------------------------------------------------------\n";
    EXPECT_EQ(output, expectedOutput);

}

TEST(TestOldMaidUI, OutOfGameTest) {
    OldMaidUI ui;
    Player player("Charlie");
    testing::internal::CaptureStdout();
    ui.outOfGame(&player);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Charlie is out of the game.\n");
}