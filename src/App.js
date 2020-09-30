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

var countProblems = (difficulty) => 
{
    let count = 0;
    const keys = Object.keys(data);
    for(let i = 0; i < keys.length; i++)
    {
        if (data[keys[i]].difficulty === difficulty)
        {
            count += 1;
        }
    }
    return count;
}

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
                <NavbarBrand href="./">Leetcode Solutions</NavbarBrand>
                <NavbarText>
                    <a
                        href="https://www.github.com/temanisparsh/leetcode"
                        target="_blank"
                    >
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
                        All {countProblems("Easy") + countProblems("Medium") + countProblems("Hard")  }
                    </Button>
                    <Button
                        className="btn btn-dark"
                        color="light"
                        onClick={() => updateDifficulty("Easy")}
                    >
                        Easy {countProblems("Easy")}
                    </Button>
                    <Button
                        className="btn btn-dark"
                        color="light"
                        onClick={() => updateDifficulty("Medium")}
                    >
                        Medium {countProblems("Medium")}
                    </Button>
                    <Button
                        className="btn btn-dark"
                        color="light"
                        onClick={() => updateDifficulty("Hard")}
                    >
                        Hard {countProblems("Hard")}
                    </Button>
                </ButtonGroup>
            </div>
            <div className="problems">
                {_.map(problems, (problem) => (
                    <a
                        onClick={() => updateProblem(problem.number)}
                        href={"#" + problem.number}
                        key={problem.number}
                        className="problem-card"
                    >
                        {problem["number"] + ".   " + problem["name"]}
                    </a>
                ))}
            </div>
            {!problems.length && difficulty !== "All" && (
                <div className="main-error">
                    No Problems found in this section
                </div>
            )}
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
                            <a href={data[problem].link} target="_blank">
                                {data[problem].number +
                                    ".   " +
                                    data[problem].name}
                            </a>
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
                    <div>Select a problem to view the solution.</div>
                </div>
            )}

            {window.innerWidth < 760 && isOpen && problem && (
                <div className="problem-modal">
                    <Modal isOpen={isOpen} toggle={toggleModal}>
                        <ModalHeader toggle={toggleModal}>
                            <a className="problem-statement-link" href={data[problem].link} target="_blank">
                                {data[problem].number +
                                    ".   " +
                                    data[problem].name}
                            </a>
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

    useEffect(() => {
        const problemId = window.location.hash.substring(1);
        if (data[problemId]) updateProblem(problemId);
    }, [window.location]);

    return (
        <div className="app">
            <Main {...{ updateProblem }} />
            <Problem {...{ problem, updateProblem }} />
        </div>
    );
};

export default App;
