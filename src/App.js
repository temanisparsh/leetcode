import React, { useState, useEffect } from "react";
import _ from "lodash";

import "./App.css";
import "bootstrap/dist/css/bootstrap.min.css";

import {
    Button,
    ButtonGroup,
    Modal,
    ModalBody,
    ModalHeader,
    Navbar,
    NavbarBrand,
    NavbarText,
} from "reactstrap";

import { LiveProvider, LiveEditor } from "react-live";
import dracula from "prism-react-renderer/themes/dracula";

import data from "./solutions.json";

var parse = require("html-react-parser");

const Main = ({ updateProblem }) => {
    const [difficulty, updateDifficulty] = useState("Easy");
    const [problems, updateProblems] = useState([]);

    useEffect(() => {
        if (difficulty === "All") {
            updateProblems(data);
            return;
        }
        updateProblems(
            _.filter(data, (prob) => prob.difficulty === difficulty)
        );
    }, [difficulty]);

    return (
        <div className="main">
            <Navbar>
                <NavbarBrand href="/">Leetcode Solutions</NavbarBrand>
                <NavbarText>
                    <a href="https://www.github.com/temanisparsh/leetcode" target="_blank" >
                        Source Code
                    </a>
                </NavbarText>
            </Navbar>
            <div className="button-group">
                <ButtonGroup size="lg">
                    <Button
                        className="btn btn-dark"
                        color="light"
                        onClick={() => updateDifficulty("All")}
                    >
                        All
                    </Button>
                    <Button
                        className="btn btn-dark"
                        color="light"
                        onClick={() => updateDifficulty("Easy")}
                    >
                        Easy
                    </Button>
                    <Button
                        className="btn btn-dark"
                        color="light"
                        onClick={() => updateDifficulty("Medium")}
                    >
                        Medium
                    </Button>
                    <Button
                        className="btn btn-dark"
                        color="light"
                        onClick={() => updateDifficulty("Hard")}
                    >
                        Hard
                    </Button>
                </ButtonGroup>
            </div>
            <div className="problems">
                {_.map(problems, (problem) => (
                    <div
                        className="problem-card"
                        onClick={() => updateProblem(problem.number)}
                        key={problem.number}
                    >
                        {problem["number"] + ".   " + problem["name"]}
                    </div>
                ))}
            </div>
            {
                (!problems.length && difficulty !== 'All') && (
                    <div className="main-error">
                        No Problems found in this section
                    </div>
                )
            }
        </div>
    );
};

const Problem = ({ problem, updateProblem }) => {
    const [isOpen, updateModal] = useState(problem ? true : false);

    const toggleModal = () => {
        updateModal(!isOpen);
        updateProblem(null);
    };

    useEffect(() => {
        if (window.innerWidth < 760 && problem) updateModal(true);
    }, [problem]);

    return (
        <div className="problem">
            {!isOpen && problem && (
                <div className="problem-desktop">
                    <div className="problem-statement">
                        <h4>
                            {data[problem].number + ".   " + data[problem].name}
                        </h4>
                        {parse(data[problem].statement)}
                    </div>
                    <LiveProvider
                        code={
                            "Solution in " +
                            data[problem].language +
                            ":\n\n" +
                            data[problem].solution
                        }
                        theme={dracula}
                        disabled={true}
                        language="cpp"
                    >
                        <LiveEditor />
                    </LiveProvider>
                </div>
            )}

            {!isOpen && !problem && (
                <div className="problem-error">
                    Select a problem to view the solution.
                </div>
            )}

            {window.innerWidth < 760 && isOpen && problem && (
                <div className="problem-modal">
                    <Modal isOpen={isOpen} toggle={toggleModal}>
                        <ModalHeader toggle={toggleModal}>
                            {data[problem].number + ".   " + data[problem].name}
                        </ModalHeader>
                        <ModalBody>
                            <div className="problem-statement">
                                {parse(data[problem].statement)}
                            </div>
                            <LiveProvider
                                code={data[problem].solution}
                                theme={dracula}
                                disabled={true}
                                language="cpp"
                            >
                                <LiveEditor />
                            </LiveProvider>
                        </ModalBody>
                    </Modal>
                </div>
            )}
        </div>
    );
};

const App = () => {
    const [problem, updateProblem] = useState(null);

    return (
        <div className="app">
            <Main {...{ updateProblem }} />
            <Problem {...{ problem, updateProblem }} />
        </div>
    );
};

export default App;
