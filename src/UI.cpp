#include <SFML/Graphics.hpp>
#include "../include/UI.h"
#include <vector>
#include <iostream>

using namespace std;

UI::UI(Graph &graph, BFS &bfsAlg, DFS &dfsAlg, ArticleMapper &mapper)
    : g(graph), bfs(bfsAlg), dfs(dfsAlg), articleMapper(mapper) {}

void UI::start() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Wiki Path Finder");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("../../data/arial.ttf")) {
        cerr << "Error: Unable to load font!" << endl;
        return;
    }

    sf::RectangleShape sourceBox(sf::Vector2f(200, 40));
    sourceBox.setPosition(100, 50);
    sourceBox.setFillColor(sf::Color::White);

    sf::RectangleShape targetBox(sf::Vector2f(200, 40));
    targetBox.setPosition(500, 50);
    targetBox.setFillColor(sf::Color::White);

    sf::RectangleShape submitButton(sf::Vector2f(100, 40));
    submitButton.setPosition(350, 120);
    submitButton.setFillColor(sf::Color::Blue);

    sf::Text submitText("Submit", font, 20);
    submitText.setPosition(365, 125);
    submitText.setFillColor(sf::Color::White);

    sf::Text sourceText("", font, 20);
    sourceText.setPosition(110, 55);
    sourceText.setFillColor(sf::Color::Black);

    sf::Text targetText("", font, 20);
    targetText.setPosition(510, 55);
    targetText.setFillColor(sf::Color::Black);

    string sourceInput = "", targetInput = "";
    bool isSourceActive = true;
    vector<string> path;
    bool showPath = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::TextEntered) {
                if (isSourceActive) {
                    if (event.text.unicode == '\b' && !sourceInput.empty()) {
                        sourceInput.pop_back();
                    } else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                        sourceInput += static_cast<char>(event.text.unicode);
                    }
                    sourceText.setString(sourceInput);
                } else {
                    if (event.text.unicode == '\b' && !targetInput.empty()) {
                        targetInput.pop_back();
                    } else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                        targetInput += static_cast<char>(event.text.unicode);
                    }
                    targetText.setString(targetInput);
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (sourceBox.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    isSourceActive = true;
                } else if (targetBox.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    isSourceActive = false;
                } else if (submitButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    int source = articleMapper.getArticleIndex(sourceInput);
                    int target = articleMapper.getArticleIndex(targetInput);

                    if (source == -1 || target == -1) {
                        cerr << "Invalid input: Source or target article not found." << endl;
                        continue;
                    }

                    auto bfsResult = bfs.findPath(sourceInput, targetInput);
                    vector<string> bfsPath = bfsResult.first;

                    auto dfsResult = dfs.findPath(sourceInput, targetInput);
                    vector<string> dfsPath = dfsResult.first;

                    if (!bfsPath.empty() && (dfsPath.empty() || bfsPath.size() <= dfsPath.size())) {
                        path = bfsPath;
                    } else {
                        path = dfsPath;
                    }
                    showPath = true;
                }
            }
        }

        window.clear(sf::Color::Cyan);

        window.draw(sourceBox);
        window.draw(targetBox);
        window.draw(sourceText);
        window.draw(targetText);

        window.draw(submitButton);
        window.draw(submitText);

        if (showPath && !path.empty()) {
            float x = 100.0f;
            for (size_t i = 0; i < path.size(); ++i) {
                sf::CircleShape node(25);
                node.setFillColor(sf::Color::White);
                node.setOutlineColor(sf::Color::Black);
                node.setOutlineThickness(2);
                node.setPosition(x, 300);
                window.draw(node);

                sf::Text nodeText(path[i], font, 15);
                nodeText.setPosition(x + 5, 310);
                nodeText.setFillColor(sf::Color::Black);
                window.draw(nodeText);

                x += 150.0f;
                if (i < path.size() - 1) {
                    sf::Vertex line[] = {
                        sf::Vertex(sf::Vector2f(x - 125, 325), sf::Color::Magenta),
                        sf::Vertex(sf::Vector2f(x - 50, 325), sf::Color::Magenta)};
                    window.draw(line, 2, sf::Lines);
                }
            }
        }

        window.display();
    }
}
