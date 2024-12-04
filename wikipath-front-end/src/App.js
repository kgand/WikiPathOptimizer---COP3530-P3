import React, { useState, useEffect } from "react";
import axios from "axios";

function App() {
  const [topics, setTopics] = useState([]);
  const [filteredTopicsStart, setFilteredTopicsStart] = useState([]);
  const [filteredTopicsEnd, setFilteredTopicsEnd] = useState([]);
  const [start, setStart] = useState("");
  const [end, setEnd] = useState("");
  const [algorithm, setAlgorithm] = useState("quickest"); // Default to "Quickest Algorithm"
  const [result, setResult] = useState(null);
  const [quickestResult, setQuickestResult] = useState(null);
  const [shortestResult, setShortestResult] = useState(null);
  const [showDropdownStart, setShowDropdownStart] = useState(false);
  const [showDropdownEnd, setShowDropdownEnd] = useState(false);
  const [error, setError] = useState("");

  useEffect(() => {
    const fetchTopics = async () => {
      try {
        const response = await axios.get("http://localhost:8070/topics");
        setTopics(response.data || []);
      } catch (error) {
        console.error("Error fetching topics:", error);
        setTopics([]);
      }
    };
    fetchTopics();
  }, []);

  const handleStartChange = (e) => {
    const value = e.target.value;
    setStart(value);
    setShowDropdownStart(true);
    setFilteredTopicsStart(
      topics.filter((topic) => topic.toLowerCase().startsWith(value.toLowerCase()))
    );
  };

  const handleEndChange = (e) => {
    const value = e.target.value;
    setEnd(value);
    setShowDropdownEnd(true);
    setFilteredTopicsEnd(
      topics.filter((topic) => topic.toLowerCase().startsWith(value.toLowerCase()))
    );
  };

  const handleAlgorithmChange = (e) => {
    setAlgorithm(e.target.value);
    setResult(null); // Clear results when switching algorithms
    setQuickestResult(null);
    setShortestResult(null);
    setError(""); // Clear error
  };

  const handleQuickestAlgorithm = async () => {
    if (!start || !end) {
      setError("Inputs Required!");
      return;
    }
    setError("");
    try {
      const bfsResponse = await axios.get(
        `http://localhost:8070/bfs?source=${start}&target=${end}`
      );
      const dfsResponse = await axios.get(
        `http://localhost:8070/dfs?source=${start}&target=${end}`
      );

      if (bfsResponse.data.metrics.execution_time < dfsResponse.data.metrics.execution_time) {
        setQuickestResult({
          path: bfsResponse.data.path,
          algorithm: "BFS",
          execution_time: bfsResponse.data.metrics.execution_time,
          nodes_visited: bfsResponse.data.metrics.nodes_visited,
          path_length: bfsResponse.data.metrics.path_length,
        });
      } else {
        setQuickestResult({
          path: dfsResponse.data.path,
          algorithm: "DFS",
          execution_time: dfsResponse.data.metrics.execution_time,
          nodes_visited: dfsResponse.data.metrics.nodes_visited,
          path_length: dfsResponse.data.metrics.path_length,
        });
      }
    } catch (error) {
      console.error("Error fetching quickest algorithm data:", error);
      setQuickestResult({ error: "Failed to fetch quickest algorithm. Please try again." });
    }
  };

  const handleShortestAlgorithm = async () => {
    if (!start || !end) {
      setError("Inputs Required!");
      return;
    }
    setError("");
    try {
      const bfsResponse = await axios.get(
        `http://localhost:8070/bfs?source=${start}&target=${end}`
      );
      const dfsResponse = await axios.get(
        `http://localhost:8070/dfs?source=${start}&target=${end}`
      );

      if (bfsResponse.data.metrics.path_length < dfsResponse.data.metrics.path_length) {
        setShortestResult({
          path: bfsResponse.data.path,
          algorithm: "BFS",
          execution_time: bfsResponse.data.metrics.execution_time,
          nodes_visited: bfsResponse.data.metrics.nodes_visited,
          path_length: bfsResponse.data.metrics.path_length,
        });
      } else {
        setShortestResult({
          path: dfsResponse.data.path,
          algorithm: "DFS",
          execution_time: dfsResponse.data.metrics.execution_time,
          nodes_visited: dfsResponse.data.metrics.nodes_visited,
          path_length: dfsResponse.data.metrics.path_length,
        });
      }
    } catch (error) {
      console.error("Error fetching shortest algorithm data:", error);
      setShortestResult({ error: "Failed to fetch shortest algorithm. Please try again." });
    }
  };

  const handleTraversalAlgorithm = async () => {
    if (!start || !end) {
      setError("Inputs Required!");
      return;
    }
    setError("");
    try {
      const bfsResponse = await axios.get(
        `http://localhost:8070/bfs?source=${start}&target=${end}`
      );
      const dfsResponse = await axios.get(
        `http://localhost:8070/dfs?source=${start}&target=${end}`
      );

      if (algorithm === "bfs") {
        setResult(bfsResponse.data);
      } else {
        setResult(dfsResponse.data);
      }
    } catch (error) {
      console.error("Error fetching traversal algorithm data:", error);
      setResult({ error: "Failed to fetch traversal algorithm. Please try again." });
    }
  };

  const handleSearch = () => {
    if (algorithm === "quickest") {
      handleQuickestAlgorithm();
    } else if (algorithm === "shortest") {
      handleShortestAlgorithm();
    } else if (algorithm === "bfs" || algorithm === "dfs") {
      handleTraversalAlgorithm();
    }
  };

  return (
    <div style={{ textAlign: "center", backgroundColor: "#80015a", padding: "20px", height: "500vh"}}>
      <h1 style={{ color: "white", marginTop: "100px", fontSize: "60px" }}>Welcome to WikiPath</h1>
      <h2 style={{ color: "white", fontSize: "35px", marginTop: "-25px" }}>Enter two topics</h2>
      <p style={{ color: "white", fontSize: "25px", marginBottom: "50px" }}>
        Select two topics from the dropdowns to see how they are connected through Wikipedia!
      </p>

      {/* Topic Inputs */}
      <div style={{ marginBottom: "20px" }}>
        <div style={{ position: "relative", display: "inline-block", marginRight: "30px" }}>
          <input
            type="text"
            placeholder="Start Topic"
            value={start}
            onChange={handleStartChange}
            onClick={() => setShowDropdownStart(!showDropdownStart)}
            style={{
              width: "500px",
              padding: "5px",
              borderRadius: "5px",
              border: "1px solid #ccc",
              fontSize: "15px"
            }}
          />
          {showDropdownStart && filteredTopicsStart.length > 0 && (
            <div
              style={{
                position: "absolute",
                background: "white",
                border: "1px solid #ccc",
                width: "500px",
                zIndex: 1000,
                marginTop: "5px",
                maxHeight: "150px",
                overflowY: "auto",
                fontSize: "15px"
              }}
            >
              {filteredTopicsStart.map((topic) => (
                <div
                  key={topic}
                  onClick={() => {
                    setStart(topic);
                    setShowDropdownStart(false);
                  }}
                  style={{
                    padding: "5px",
                    cursor: "pointer",
                    fontSize: "15px"
                  }}
                >
                  {topic}
                </div>
              ))}
            </div>
          )}
        </div>

        <div style={{ position: "relative", display: "inline-block" }}>
          <input
            type="text"
            placeholder="End Topic"
            value={end}
            onChange={handleEndChange}
            onClick={() => setShowDropdownEnd(!showDropdownEnd)}
            style={{
              width: "500px",
              padding: "5px",
              borderRadius: "5px",
              border: "1px solid #ccc",
              fontSize: "15px"
            }}
          />
          {showDropdownEnd && filteredTopicsEnd.length > 0 && (
            <div
              style={{
                position: "absolute",
                background: "white",
                border: "1px solid #ccc",
                width: "500px",
                zIndex: 1000,
                marginTop: "5px",
                maxHeight: "150px",
                overflowY: "auto",
              }}
            >
              {filteredTopicsEnd.map((topic) => (
                <div
                  key={topic}
                  onClick={() => {
                    setEnd(topic);
                    setShowDropdownEnd(false);
                  }}
                  style={{
                    padding: "5px",
                    cursor: "pointer",
                    fontSize: "15px"
                  }}
                >
                  {topic}
                </div>
              ))}
            </div>
          )}
        </div>
      </div>

      {/* Error Message */}
      {error && (
        <p style={{ color: "white", fontWeight: "bold", marginTop: "30px", fontSize: "20px" }}>{error}</p>
      )}

      {/* Algorithm Selection */}
      <div style={{ marginTop: "10px" }}>
        <select
          value={algorithm}
          onChange={handleAlgorithmChange}
          style={{
            marginRight: "10px",
            padding: "5px",
            borderRadius: "5px",
            border: "1px solid #ccc",
            marginTop: "20px",
            fontSize: "20px"

          }}
        >
          <option value="quickest">Quickest Algorithm</option>
          <option value="shortest">Shortest Path</option>
          <option value="bfs">BFS</option>
          <option value="dfs">DFS</option>
        </select>
        <button
          onClick={handleSearch}
          style={{
            padding: "7px 10px",
            borderRadius: "5px",
            backgroundColor: "#c259a2",
            color: "white",
            border: "none",
            cursor: "pointer",
            fontSize: "20px"
          }}
        >
          Submit
        </button>
      </div>

      {result && algorithm !== "quickest" && algorithm !== "shortest" && (
        <div style={{ marginTop: "20px", textAlign: "center", color: "white" }}>
          <h3 style={{ fontSize: "30px" }}>Result:</h3>
          {result.error ? (
            // error so no path found
            <div
              style={{
                color: "white",
                fontSize: "20px",
                textAlign: "center",
              }}
            >
              <strong>No path found.</strong>
            </div>
          ) : (
            // display path if no error
            <div
              style={{
                display: "flex",
                justifyContent: "center",
                alignItems: "center",
                flexWrap: "wrap",
                margin: "auto",
                maxWidth: "90vw",
              }}
            >
              {result.path?.map((word, index) => (
                <React.Fragment key={index}>
                  <a
                    href={`https://en.wikipedia.org/wiki/${word}`}
                    target="_blank"
                    rel="noopener noreferrer"
                    style={{ textDecoration: "none" }}
                  >
                    <div
                      style={{
                        padding: "10px 15px",
                        backgroundColor: "white",
                        borderRadius: "10px",
                        color: "black",
                        margin: "5px",
                        textAlign: "center",
                      }}
                    >
                      {word.replace(/_/g, " ")}
                    </div>
                  </a>
                  {index < result.path.length - 1 && (
                    <span
                      style={{
                        margin: "0 10px",
                        fontSize: "20px",
                        color: "white",
                      }}
                    >
                      →
                    </span>
                  )}
                </React.Fragment>
              ))}
            </div>
          )}
          {!result.error && (
            // show metrics if no error
            <>
              <p style={{ fontSize: "25px" }}><strong>Nodes Visited:</strong> {result.metrics?.nodes_visited}</p>
              <p style={{ fontSize: "25px" }}><strong>Execution Time:</strong> {result.metrics?.execution_time} μs</p>
              <p style={{ fontSize: "25px" }}><strong>Path Length:</strong> {result.metrics?.path_length}</p>
            </>
          )}
        </div>
      )}


      {/* Shortest Path Result */}
      {shortestResult && algorithm === "shortest" && (
        <div style={{ marginTop: "20px", textAlign: "center", color: "white" }}>
          <h3 style={{ fontSize: "30px" }}>Shortest Path Result:</h3>
          {shortestResult.error ? (
            // error so no path found
            <div
              style={{
                color: "white",
                fontSize: "20px",
                textAlign: "center",
              }}
            >
              <strong>No path found.</strong>
              </div>
          ) : (
            // display path if no error
            <div
              style={{
                display: "flex",
                justifyContent: "center",
                alignItems: "center",
                flexWrap: "wrap",
                margin: "auto",
                maxWidth: "90vw",
              }}
            >
              {shortestResult.path?.map((word, index) => (
                <React.Fragment key={index}>
                  <a
                    href={`https://en.wikipedia.org/wiki/${word}`}
                    target="_blank"
                    rel="noopener noreferrer"
                    style={{ textDecoration: "none" }}
                  >
                    <div
                      style={{
                        padding: "10px 15px",
                        backgroundColor: "white",
                        borderRadius: "10px",
                        color: "black",
                        margin: "5px",
                        textAlign: "center",
                      }}
                    >
                      {word.replace(/_/g, " ")}
                    </div>
                  </a>
                  {index < shortestResult.path.length - 1 && (
                    <span
                      style={{
                        margin: "0 10px",
                        fontSize: "20px",
                        color: "white",
                      }}
                    >
                      →
                    </span>
                  )}
                </React.Fragment>
              ))}
            </div>
          )}
          {!shortestResult.error && (
            // show metrics if no error
            <>
              <p style={{ fontSize: "25px" }}><strong>Nodes Visited:</strong> {shortestResult.nodes_visited}</p>
              <p style={{ fontSize: "25px" }}><strong>Execution Time:</strong> {shortestResult.execution_time} μs</p>
              <p style={{ fontSize: "25px" }}><strong>Path Length:</strong> {shortestResult.path_length}</p>
            </>
          )}
        </div>
      )}


      {/* Quickest Path Result */}
      {quickestResult && algorithm === "quickest" && (
        <div style={{ marginTop: "20px", textAlign: "center", color: "white" }}>
          <h3 style={{ fontSize: "30px" }}>Quickest Algorithm Result:</h3>
          {quickestResult.error ? (
            // error so no path found
            <div
              style={{
                color: "white",
                fontSize: "20px",
                textAlign: "center",
              }}
            >
              <strong>No path found.</strong>
            </div>
          ) : (
            // display path if no error
            <div
              style={{
                display: "flex",
                justifyContent: "center",
                alignItems: "center",
                flexWrap: "wrap",
                margin: "auto",
                maxWidth: "90vw",
              }}
            >
              {quickestResult.path?.map((word, index) => (
                <React.Fragment key={index}>
                  <a
                    href={`https://en.wikipedia.org/wiki/${word}`}
                    target="_blank"
                    rel="noopener noreferrer"
                    style={{ textDecoration: "none" }}
                  >
                    <div
                      style={{
                        padding: "10px 15px",
                        backgroundColor: "white",
                        borderRadius: "10px",
                        color: "black",
                        margin: "5px",
                        textAlign: "center",
                      }}
                    >
                      {word.replace(/_/g, " ")}
                    </div>
                  </a>
                  {index < quickestResult.path.length - 1 && (
                    <span
                      style={{
                        margin: "0 10px",
                        fontSize: "20px",
                        color: "white",
                      }}
                    >
                      →
                    </span>
                  )}
                </React.Fragment>
              ))}
            </div>
          )}
          {!quickestResult.error && (
            // show metrics if no error
            <>
              <p style={{ fontSize: "25px" }}><strong>Nodes Visited:</strong> {quickestResult.nodes_visited}</p>
              <p style={{ fontSize: "25px" }}><strong>Execution Time:</strong> {quickestResult.execution_time} μs</p>
              <p style={{ fontSize: "25px" }}><strong>Path Length:</strong> {quickestResult.path_length}</p>
            </>
          )}
        </div>
      )}
    </div>
  );
}

export default App;
