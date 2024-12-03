import React, { useState } from "react";
import axios from "axios";

function App() {
  const [start, setStart] = useState("");
  const [end, setEnd] = useState("");
  const [algorithm, setAlgorithm] = useState("bfs");
  const [result, setResult] = useState(null);

  const handleSearch = async () => {
    try {
      const response = await axios.get(
        `http://localhost:8070/${algorithm}?source=${start}&target=${end}`
      );
      setResult(response.data);
    } catch (error) {
      console.error("Error fetching data:", error);
      setResult({ error: "Failed to fetch path. Please try again." });
    }
  };

  return (
    <div style={{ textAlign: "center", marginTop: "50px" }}>
      <h1>Enter two topics:</h1>
      <div>
        <input
          type="text"
          placeholder="Dog"
          value={start}
          onChange={(e) => setStart(e.target.value)}
          style={{
            width: "150px",
            marginRight: "10px",
            padding: "5px",
            borderRadius: "5px",
            border: "1px solid #ccc",
          }}
        />
        <input
          type="text"
          placeholder="Shang Dynasty"
          value={end}
          onChange={(e) => setEnd(e.target.value)}
          style={{
            width: "150px",
            marginRight: "10px",
            padding: "5px",
            borderRadius: "5px",
            border: "1px solid #ccc",
          }}
        />
      </div>
      <div style={{ marginTop: "10px" }}>
        <select
          value={algorithm}
          onChange={(e) => setAlgorithm(e.target.value)}
          style={{
            marginRight: "10px",
            padding: "5px",
            borderRadius: "5px",
            border: "1px solid #ccc",
          }}
        >
          <option value="bfs">BFS</option>
          <option value="dfs">DFS</option>
        </select>
        <button
          onClick={handleSearch}
          style={{
            padding: "5px 10px",
            borderRadius: "5px",
            backgroundColor: "#007BFF",
            color: "white",
            border: "none",
            cursor: "pointer",
          }}
        >
          Submit
        </button>
      </div>

      {result && (
        <div style={{ marginTop: "20px", textAlign: "left", display: "inline-block" }}>
          <h3>Result:</h3>
          {result.error ? (
            <p style={{ color: "red" }}>{result.error}</p>
          ) : (
            <div>
              <p><strong>Path:</strong> {result.path.join(" → ")}</p>
              <p><strong>Nodes Visited:</strong> {result.metrics.nodes_visited}</p>
              <p><strong>Execution Time:</strong> {result.metrics.execution_time} μs</p>
              <p><strong>Path Length:</strong> {result.metrics.path_length}</p>
            </div>
          )}
        </div>
      )}
    </div>
  );
}

export default App;
